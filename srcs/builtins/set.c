/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/18 20:07:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	is_formated(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && !ft_isalnum(str[i]))
		return (-1);
	i++;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	check_variable(char **cmds, int i)
{
	if (cmds[i] && cmds[i + 1] && cmds[i + 2])
	{
		print_err("set: Too many arguments.", "");
		return (1);
	}
	else if (is_formated(cmds[i]) == -1)
	{
		print_err("set: Variable name must begin with a letter.", "");
		return (1);
	}
	else if (is_formated(cmds[i]) == 0)
	{
		print_err("set: Variable name must contain ",
			"alphanumeric characters.");
		return (1);
	}
	else
		return (0);
}

int			builtins_set(t_list **env, char **cmds)
{
	t_list	**l_var;
	int		i;

	UNUSED(env);
	i = 1;
	if (cmds[i] && ft_strcmp(cmds[i], "-g") == 0)
	{
		l_var = &g_g_vars;
		i++;
	}
	else
		l_var = &g_l_vars;
	if (!cmds[i])
		return (vars_show(*l_var));
	else if (check_variable(cmds, i) != 0)
		return (1);
	else
	{
		if (!cmds[i + 1])
			vars_add_or_modify(l_var, cmds[i], "");
		else
			vars_add_or_modify(l_var, cmds[i], cmds[i + 1]);
		return (0);
	}
}
