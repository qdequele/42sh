/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 23:02:59 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int				builtins_jobs(t_list **env, char **cmds)
{
	t_shell		*shell;
	t_list		*job_list;
	int			i;

	UNUSED(env);
	UNUSED(cmds);
	shell = recover_shell();
	job_list = shell->jobs;
	i = 1;
	while (job_list)
	{
		if (!((t_job *)job_list->content)->notified)
			put_job_info(job_list->content, i);
		i++;
		job_list = job_list->next;
	}
	return (0);
}

static void		free_one_process(void *elem, size_t size)
{
	t_process	*l_process;
	int			i;

	i = -1;
	l_process = elem;
	UNUSED(size);
	if (l_process->argv)
		ft_free_aoc(l_process->argv);
	while (++i < 3)
	{
		if (l_process->stdio[i].target)
		{
			free(l_process->stdio[i].target);
			l_process->stdio[i].target = NULL;
		}
	}
	free(elem);
}

void			free_one_job(void *elem, size_t size)
{
	t_job		*l_job;

	UNUSED(size);
	l_job = elem;
	ft_lstdel(&(l_job->process_list), &free_one_process);
	free(elem);
}

void			free_jobs(t_list **jobs)
{
	ft_lstdel(jobs, &free_one_job);
}
