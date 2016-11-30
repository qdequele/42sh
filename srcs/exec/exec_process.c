/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:24:02 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/19 17:25:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	assert_file(int i, char *target, int mode)
{
	struct stat		sb;
	int				flag;

	if (!target)
		return ;
	if (stat(target, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		print_err("42sh: Is a directory: ", target);
		close(i);
	}
	flag = (mode == O_RDONLY) ? R_OK : W_OK;
	if (stat(target, &sb) == 0 && access(target, flag) != 0)
	{
		print_err("42sh: Permission denied: ", target);
		close(i);
	}
}

static void	get_new_stdio(t_process *p, t_io_channel *s)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		assert_file(i, s[i].target, s[i].open_mode);
		if (s[i].target && s[i].open_mode == O_RDONLY &&
			(s[i].fd = open(s[i].target, O_RDONLY)) == -1)
		{
			print_err("42sh: No such file or directory", "");
			exit(1);
		}
		else if (s[i].target && (s[i].fd =
			open(s[i].target, s[i].open_mode, 0666)) == -1)
			s[i].fd = 1;
	}
	i = -1;
	while (++i < 3)
		if (s[i].fd != i)
			dup2(p->stdio[i].fd, i);
	i = -1;
	while (++i < 3)
		if (s[i].dead_end)
			close(i);

}

void		launch_process_builtin(t_process *p)
{
	int		save_stdio[3];

	save_stdio[0] = dup(0);
	save_stdio[1] = dup(1);
	save_stdio[2] = dup(2);
	if (p->stdio[1].aggr == 1)
		close(p->stdio[1].fd);
	get_new_stdio(p, p->stdio);
	p->status = builtins_exec(&g_env, p->argv);
	p->completed = 1;
	dup2(save_stdio[0], 0);
	dup2(save_stdio[1], 1);
	dup2(save_stdio[2], 2);
}

void		launch_process(t_process *p, pid_t pgid, int foreground)
{
	char			**env;
	pid_t			pid;
	struct stat		sb;

	if (!p)
		exit(1);
	pid = getpid();
	if (pgid == 0)
		pgid = pid;
	setpgid(pid, pgid);
	if (foreground)
		tcsetpgrp(0, pgid);
	env = env_parse_from_list(g_env);
	reset_major_signals();
	get_new_stdio(p, p->stdio);
	if (p->argv && p->argv[0] && p->argv[0][0] == '!')
		exit(0);
	execve(p->argv[0], p->argv, env);
	if (stat(p->argv[0], &sb) == 0 && access(p->argv[0], X_OK) != 0)
		print_err("42sh: Permission denied: ", p->argv[0]);
	else
		print_err("42sh: command not found: ", p->argv[0]);
	exit(127);
}

int			update_process_status(t_job *j, pid_t pid, int status)
{
	t_list	*process;

	process = j->process_list;
	while (process)
	{
		if (((t_process *)process->content)->pid == pid)
		{
			if (WIFEXITED(status) || WIFSIGNALED(status) || WIFSTOPPED(status))
			{
				if (!WIFSTOPPED(status))
				{
					((t_process *)process->content)->status = status;
					((t_process *)process->content)->completed = 1;
					if (process->next == NULL)
						kill(j->pgid, SIGTERM);
				}
				else
					((t_process *)process->content)->stopped = 1;
			}
			return (0);
		}
		process = process->next;
	}
	return (0);
}
