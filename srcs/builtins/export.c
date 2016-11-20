/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 18:32:40 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_export(t_list **env, char **cmds)
{
	int		i;
	char	*value;

	(void)env;
	i = 1;
	if (!cmds[i])
	{
		print_err("export: Need an argument.", "");
		return (1);
	}
	while (cmds[i])
	{
		value = vars_get(g_vars, cmds[i]);
		if (!value)
			print_err("export: Impossible to find ", cmds[i]);
		else
		{
			vars_add_or_modify(&g_env, cmds[i], value);
			vars_add_or_modify(vars_recover(), cmds[i], value);
		}
		i++;
	}
	return (0);
}
