/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:24:02 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/29 17:38:41 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	get_new_stdio(t_process *p, t_io_channel *s)
{
	__DEBUG__
	if (s[0].fd != 0)
	{
		printf("new_stdio 1\n");
		dup2(p->stdio[0].fd, 0);
	}
	if (s[1].fd != 1)
	{
		printf("new_stdio 2\n");
		dup2(p->stdio[1].fd, 1);
	}
	if (s[2].fd != 2)
	{
		printf("new_stdio 3\n");
		dup2(p->stdio[2].fd, 2);
	}
	if (s[0].dead_end)
	{
		printf("new_stdio 4\n");
		close(0);
	}
	if (s[1].dead_end)
	{
		printf("new_stdio 5\n");
		close(1);
	}
	if (s[2].dead_end)
	{
		printf("new_stdio 6\n");
		close(2);
	}
	printf("new_stdio 7\n");
}

void		launch_process_builtin(t_process *p)
{
	int		save_stdio[3];

	__DEBUG__
	save_stdio[0] = dup(0);
	save_stdio[1] = dup(1);
	save_stdio[2] = dup(2);
	get_new_stdio(p, p->stdio);
	p->status = builtins_exec(&g_env, p->argv);
	p->completed = 1;
	dup2(save_stdio[0], 0);
	dup2(save_stdio[1], 1);
	dup2(save_stdio[2], 2);
}

void		launch_process(t_process *p, pid_t pgid, int foreground)
{
	char	**env;
	pid_t	pid;

	// __DEBUG__
	// UNUSED(p);
	// UNUSED(pgid);
	// UNUSED(foreground);
	if (!p)
		exit(1);
	pid = getpid();
	printf("pid : %d - gpid : %d\n", pid, pgid);
	if (pgid == 0)
		pgid = pid;
	printf("pid : %d - gpid : %d\n", pid, pgid);
	setpgid(pid, pgid);
	if (foreground)
		tcsetpgrp(0, pgid);
	env = env_parse_from_list(g_env);
	reset_major_signals();
	get_new_stdio(p, p->stdio);
	execve(p->argv[0], p->argv, env);
	ft_putstr("42sh: command not found: ");
	ft_putendl(p->argv[0]);
	exit(1);
}

int			update_process_status(t_job *j, pid_t pid, int status)
{
	t_list	*process;

	__DEBUG__
	process = j->process_list;
	while (process)
	{
		__DEBUG__
		if (((t_process *)process->content)->pid == pid)
		{
			__DEBUG__
			if (WIFEXITED(status))
			{
				__DEBUG__
				((t_process *)process->content)->status = status;
				((t_process *)process->content)->completed = 1;
			}
			if (WIFSIGNALED(status))
			{
				__DEBUG__
				((t_process *)process->content)->status = status;
				((t_process *)process->content)->completed = 1;
			}
			if (WIFSTOPPED(status))
				((t_process *)process->content)->stopped = 1;
			return (0);
			__DEBUG__
		}
		__DEBUG__
		process = process->next;
	}
	__DEBUG__
	return (0);
}
