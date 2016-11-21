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


static	int	is_formated(char *str)
{
	int	i;
	char 	*p_key;

	i = 0;
	if ((p_key = ft_strchr(str, '=')) != NULL)
		str = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(p_key));
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (-1);
	i++;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (p_key)
		free(str);
	return (1);
}

static	int	is_error(char **cmds)
{
	if (is_formated(cmds[1]) == -1)
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd(cmds[1], 2);
		ft_putendl_fd(": not valid identifier", 2);
		return (1);
	}
	return (0);
}

static 	void lets_export(char **cmds, int i)
{
	char 	*value;
	char 	*p_key;
	char 	*p_value;

	while (cmds[i])
	{
		if ((p_value = ft_strchr(cmds[i], '=')) != NULL)
		{
			p_key = ft_strsub(cmds[i], 0, ft_strlen(cmds[i]) - (ft_strlen(p_value)));
			p_value++;
			vars_add_or_modify(&g_g_vars, p_key, p_value);
			env_add_or_modify(&g_env, p_key, p_value);
			vars_add_or_modify(&g_export, p_key, p_value);
			free(p_key);
		}
		else if ((value = vars_get(g_l_vars, cmds[i])) != NULL ||
			(value = vars_get(g_export, cmds[i])) != NULL)
		{
			env_add_or_modify(&g_env, cmds[i], value);
			vars_add_or_modify(&g_g_vars, cmds[i], value);
			vars_add_or_modify(&g_export, cmds[i], value);
		}
		else if (!value)
			vars_add_or_modify(&g_export, cmds[i], "");
		i++;
	}
}

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

	i = 1;
	UNUSED(env);
	if ( !cmds[i] || (!cmds[i + 1] && ft_strcmp(cmds[i], "-p") == 0))
	{
		display_export_list(g_export);
		return (1);
	}
	if (is_error(cmds))
		return (0);
	lets_export(cmds, i);
	return (1);

}
