/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 11:43:20 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_unsetenv(t_list **env, char **cmds)
{
	int		i;

	i = 1;
	while (cmds[i])
	{
		if (env_get(*env, cmds[i]) == NULL)
			print_err(cmds[i], ": Wrong key.");
		else if (ft_strcmp(cmds[i], "PATH") == 0)
			env_add_or_modify(&g_env, cmds[i],
				"/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/sbin");
		else
			remove_key(env, cmds[i], &env_free_one);
		i++;
	}
	g_env = *env;
	return (0);
}
