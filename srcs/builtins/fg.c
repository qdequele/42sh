/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:38:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int		builtin_fg_default(void)
{
	t_job	*job;

	job = find_job_by_index(1);
	if (!job)
	{
		print_err("fg: no current job.", "");
		return (1);
	}
	put_job_in_foreground(job, 1);
	return (0);
}

int				builtins_fg(t_list **env, char **cmds)
{
	int		i;
	t_job	*job;

	i = 1;
	UNUSED(env);
	while (cmds[i])
	{
		job = find_job_by_index(ft_atoi(cmds[i]));
		if (job)
			put_job_in_foreground(job, 1);
		else
		{
			print_err("fg: job not found: ", cmds[i]);
			return (1);
		}
		i++;
	}
	if (cmds[1] == NULL)
		return (builtin_fg_default());
	else
		return (0);
}
