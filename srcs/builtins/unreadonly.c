/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unreadonly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 18:39:32 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_unreadonly(t_list **env, char **cmds)
{
	t_list	**l_var;
	int		i;

	(void)env;
	i = 1;
	if (cmds[i] && ft_strcmp(cmds[i], "-g") == 0)
	{
		l_var = vars_recover();
		i++;
	}
	else
		l_var = &g_vars;
	while (cmds[i])
	{
		vars_change_readonly(l_var, cmds[i], 0);
		i++;
	}
	return (0);
}
