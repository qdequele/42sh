/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 18:40:01 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_set_equal(t_list **env, char **cmds)
{
	int		i;
	char	*p_key;
	char	*p_value;

	i = 0;
	UNUSED(env);
	while (cmds[i])
	{
		if ((p_value = ft_strchr(cmds[i], '=')) != NULL)
		{
			p_key = ft_strsub(cmds[i], 0, ft_strlen(cmds[i]) -
				(ft_strlen(p_value)));
			p_value++;
			vars_add_or_modify(&g_g_vars, p_key, p_value);
			free(p_key);
		}
		else
			return (1);
		i++;
	}
	return (1);
}
