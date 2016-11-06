/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 11:42:50 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 21:54:12 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	put_job_in_background(t_job *j, int cont)
{
	t_shell	*shell;

	shell = recover_shell();
	if (cont)
		kill(-j->pgid, SIGCONT);
	ft_lstaddend(&(shell->jobs), ft_lstnew(j, sizeof(t_job)));
	put_job_info(j, find_job_index(j->pgid));
}

void	put_job_in_foreground(t_job *j, int cont)
{
	t_shell		*shell;
	t_list		*cur;

	shell = recover_shell();
	if (j->pgid > 0)
		tcsetpgrp(0, j->pgid);
	if (cont)
	{
		cur = j->process_list;
		while (cur)
		{
			((t_process *)(cur->content))->stopped = 0;
			cur = cur->next;
		}
		kill(-j->pgid, SIGCONT);
	}
	wait_for_job(j);
	log_job_exit_signal(j);
	vars_add_or_modify(&g_vars, ft_strdup("?"), ft_itoa(get_job_exit_code(j)));
	tcsetpgrp(0, shell->pgid);
}

void	wait_for_job(t_job *j)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = 0;
	while (!job_is_completed(j) && !job_is_stopped(j))
	{
		pid = waitpid(-j->pgid, &status, WUNTRACED);
		update_process_status(j, pid, status);
		if (pid == -1)
			break ;
		status = 0;
	}
}

int		job_is_completed(t_job *j)
{
	t_list		*process;
	t_process	*p;

	process = j->process_list;
	while (process)
	{
		p = process->content;
		if (!p->completed)
			return (0);
		process = process->next;
	}
	return (1);
}

int		job_is_stopped(t_job *j)
{
	t_list		*process;
	t_process	*p;

	process = j->process_list;
	while (process)
	{
		p = process->content;
		if (!p->stopped && !p->completed)
			return (0);
		process = process->next;
	}
	return (1);
}
