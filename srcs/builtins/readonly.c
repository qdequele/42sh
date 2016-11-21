/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readonly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 18:37:17 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_readonly(t_list **env, char **cmds)
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
		vars_change_readonly(l_var, cmds[i], 1);
		i++;
	}
	return (0);
}
