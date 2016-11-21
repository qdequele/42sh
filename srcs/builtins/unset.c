/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 17:59:23 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_unset(t_list **env, char **cmds)
{
	t_list	**l_var;
	int		i;

	i = 1;
	UNUSED(env);
	if (cmds[i] && ft_strcmp(cmds[i], "-g") == 0)
	{
		l_var = &g_g_vars;
		i++;
	}
	else
		l_var = &g_l_vars;
	while (cmds[i])
	{
		remove_key(l_var, cmds[i], &vars_free_one);
		i++;
	}
	return (0);
}
