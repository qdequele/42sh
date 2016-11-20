/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:38:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int		builtin_bg_default(void)
{
	t_job	*job;

	job = find_job_by_index(1);
	if (!job)
	{
		print_err("fg: no current job", "");
		return (1);
	}
	kill(-job->pgid, SIGCONT);
	put_job_info(job, find_job_index(job->pgid));
	return (0);
}

static void		builtin_bg_one(t_job *job)
{
	kill(-job->pgid, SIGCONT);
	put_job_info(job, find_job_index(job->pgid));
}

int				builtins_bg(t_list **env, char **cmds)
{
	int		i;
	t_job	*job;

	i = 1;
	UNUSED(env);
	while (cmds[i])
	{
		job = find_job_by_index(ft_atoi(cmds[i]));
		if (job)
			builtin_bg_one(job);
		else
		{
			print_err("fg: job not found: ", cmds[i]);
			return (1);
		}
		i++;
	}
	if (cmds[1] == NULL)
		return (builtin_bg_default());
	else
		return (0);
}
