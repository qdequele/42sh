/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:24:02 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 20:07:37 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	get_new_stdio(t_process *p, t_io_channel *s)
{
	if (s[0].fd != 0)
		dup2(p->stdio[0].fd, 0);
	if (s[1].fd != 1)
		dup2(p->stdio[1].fd, 1);
	if (s[2].fd != 2)
		dup2(p->stdio[2].fd, 2);
	if (s[0].dead_end)
		close(0);
	if (s[1].dead_end)
		close(1);
	if (s[2].dead_end)
		close(2);
}

void		launch_process_builtin(t_process *p)
{
	int		save_stdio[3];

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
	execve(p->argv[0], p->argv, env);
	ft_putstr("42sh: command not found: ");
	ft_putendl(p->argv[0]);
	exit(1);
}

int			update_process_status(t_job *j, pid_t pid, int status)
{
	t_list	*process;

	process = j->process_list;
	while (process)
	{
		if (((t_process *)process->content)->pid == pid)
		{
			if (WIFEXITED(status))
			{
				
				((t_process *)process->content)->status = status;
				((t_process *)process->content)->completed = 1;
			}
			if (WIFSIGNALED(status))
			{
				
				((t_process *)process->content)->status = status;
				((t_process *)process->content)->completed = 1;
			}
			if (WIFSTOPPED(status))
				((t_process *)process->content)->stopped = 1;
			return (0);
			
		}
		
		process = process->next;
	}
	
	return (0);
}
