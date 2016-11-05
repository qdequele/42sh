/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:48:42 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/20 14:18:11 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void			exec_job_list(t_list *job_list)
{
	t_job	*j;

	__DEBUG__
	while (job_list)
	{
		j = job_list->content;
		prepare_job(j);
		if (j->linker != LINK_TO_BACKGROUND)
		{
			__DEBUG__
			launch_job(job_list->content, 1);
		}
		else
		{
			__DEBUG__
			launch_job(job_list->content, 0);
		}
		if (!job_is_completed(j) && job_is_stopped(j) &&
			j->linker != LINK_TO_BACKGROUND)
		{
			__DEBUG__
			put_job_in_background(j, 0);
		}
		else if (is_job_success(j) && j->linker == LINK_OR)
		{
			__DEBUG__
			while (job_list->next && GET_JOB_LINKER(job_list) == LINK_OR)
			{
				__DEBUG__
				job_list = job_list->next;
			}
		}
		else if (!is_job_success(j) && j->linker == LINK_AND)
		{
			__DEBUG__
			while (job_list->next && GET_JOB_LINKER(job_list) == LINK_AND)
			{
				__DEBUG__
				job_list = job_list->next;
			}
		}
		__DEBUG__
		job_list = job_list->next;
		__DEBUG__
	}
}

void			launch_job_process(t_job *job, t_process *process, int *iofile,
								int foreground)
{
	__DEBUG__
	printf("iofile [%d][%d]\n", iofile[0], iofile[1]);
	if (builtins_find(*process->argv))
	{
		process->stdio[0].fd = iofile[0];
		process->stdio[1].fd = iofile[1];
		launch_process_builtin(process);
	}
	else if ((process->pid = fork()) == 0)
	{
		printf("process->stdio.fd [%d][%d]\n", process->stdio[0].fd, process->stdio[0].fd);
		if (iofile[0] != 0)
			process->stdio[0].fd = iofile[0];
		if (iofile[1] != 1)
			process->stdio[1].fd = iofile[1];
		launch_process(process, job->pgid, foreground);
	}
	if (!job->pgid)
		job->pgid = process->pid;
	setpgid(process->pid, job->pgid);
	printf("iofile [%d][%d]\n", iofile[0], iofile[1]);
	if (iofile[0] != 0)
		close(iofile[0]);
	if (iofile[1] != 1)
		close(iofile[1]);
}

void			launch_job(t_job *j, int foreground)
{
	t_list		*process_list;
	t_process	*process;
	int			iofile[2];
	int			pipe_fd[2];

	__DEBUG__
	process_list = j->process_list;
	iofile[0] = 0;
	while (process_list)
	{
		process = process_list->content;
		if (process_list->next)
		{
			pipe(pipe_fd);
			iofile[1] = pipe_fd[1];
		}
		else
			iofile[1] = 1;
		launch_job_process(j, process, iofile, foreground);
		iofile[0] = pipe_fd[0];
		process_list = process_list->next;
	}
	if (foreground)
		put_job_in_foreground(j, 0);
	else
		put_job_in_background(j, 0);
}
