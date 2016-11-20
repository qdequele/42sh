/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:38:10 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/29 17:41:59 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_job		*find_job_by_gpid(t_list *job_list, pid_t pgid)
{
	t_job	*j;

	while (job_list)
	{
		j = job_list->content;
		if (j->pgid == pgid)
			return (j);
		job_list = job_list->next;
	}
	return (NULL);
}

t_job		*find_job_by_pid(t_list *job_list, pid_t pid)
{
	t_job		*j;
	t_list		*process_list;
	t_process	*p;

	while (job_list)
	{
		j = job_list->content;
		process_list = j->process_list;
		while (process_list)
		{
			p = process_list->content;
			if (p->pid == pid)
				return (j);
			process_list = process_list->next;
		}
		job_list = job_list->next;
	}
	return (NULL);
}

int			find_job_index(pid_t pgid)
{
	t_shell	*shell;
	t_list	*job_list;
	int		i;

	shell = recover_shell();
	job_list = shell->jobs;
	i = 1;
	while (job_list)
	{
		if (((t_job *)job_list->content)->pgid == pgid)
			return (i);
		job_list = job_list->next;
		i++;
	}
	return (0);
}

t_job		*find_job_by_index(int index)
{
	t_shell	*shell;
	t_list	*job_list;
	int		i;

	shell = recover_shell();
	job_list = shell->jobs;
	i = 1;
	while (job_list)
	{
		if (i == index)
			return (job_list->content);
		job_list = job_list->next;
		i++;
	}
	return (NULL);
}

void		log_job_exit_signal(t_job *j)
{
	int		sig;
	int		exit_code;

	exit_code = get_job_raw_exit_code(j);
	if (WIFSIGNALED(exit_code))
	{
		sig = WTERMSIG(exit_code);
		if (sig == 10)
		{
			ft_putnbr(j->pgid);
			print_err("\tbus error\t", j->command);
		}
		if (sig == 11)
		{
			ft_putnbr(j->pgid);
			print_err("\tsegmentation fault\t", j->command);
		}
	}
}
