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

// int			builtins_export(t_list **env, char **cmds)
// {
// 	int		i;
// 	char	*value;

// 	(void)env;
// 	i = 1;
// 	if (!cmds[i])
// 	{
// 		print_err("export: Need an argument.", "");
// 		return (1);
// 	}
// 	while (cmds[i])
// 	{
// 		value = vars_get(g_l_vars, cmds[i]);
// 		if (!value)
// 			print_err("export: Impossible to find ", cmds[i]);
// 		else
// 		{
// 			env_add_or_modify(&g_env, cmds[i], value);
// 			vars_add_or_modify(vars_recover(), cmds[i], value);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

static 	void display_export_list(t_list *env)
{
	t_list *cur;

	cur = env;
	while (cur)
	{
		ft_putstr_fd("export ", 1);
		ft_putstr_fd((char*)((t_env *)cur->content)->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd((char*)((t_env *)cur->content)->value, 1);
		cur = cur->next;
	}
}


int 	builtins_export(t_list **env, char **cmds)
{
	int 	i;
	char 	*value;
	char 	*p_value;
	char 	*p_key;

	i = 1;
	(void)env;
	if ( !cmds[i] || (!cmds[i + 1] && ft_strcmp(cmds[i], "-p") == 0))
	{
		display_export_list(g_export);
		return (1);
	}
	while (cmds[i])
	{
		if ((p_value = ft_strchr(cmds[i], '=')) != NULL)
		{
			p_key = ft_strsub(cmds[i], 0, ft_strlen(cmds[i]) - (ft_strlen(p_value)));
			p_value++;
			vars_add_or_modify(vars_recover(), p_key, p_value);
			vars_add_or_modify(&g_env, p_key, p_value);
			free(p_key);
		}
		else if ((value = vars_get(g_l_vars, cmds[i])) != NULL)
		{
			env_add_or_modify(&g_env, cmds[i], value);
			vars_add_or_modify(vars_recover(), cmds[i], value);
		}
		else if (!value)
		{
			vars_add_or_modify(&g_export, cmds[i], "");
		}
		i++;
	}
	return (1);

}