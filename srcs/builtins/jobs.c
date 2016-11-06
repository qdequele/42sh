/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:38:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		builtins_jobs(t_list **env, char **cmds)
{
	t_shell	*shell;
	t_list	*job_list;
	int		i;

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
