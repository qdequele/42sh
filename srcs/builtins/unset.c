/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:55:24 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_unset(t_list **env, char **cmds)
{
	t_list	**l_var;
	t_list	*tmp_l_vars;
	int		i;
	
	i = 1;
	(void)env;
	if (cmds[i] && ft_strcmp(cmds[i], "-g") == 0)
	{
		tmp_l_vars = vars_recover();
		l_var = &tmp_l_vars;
		i++;
	}
	else
		l_var = &g_vars;
	while (cmds[i])
	{
		remove_key(l_var, cmds[i]);
		i++;
	}
	return (0);
}
