/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 15:52:14 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	is_formated(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]))
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
	if (cmds[i + 2])
	{
		ft_putstr_c(RED, "set: Too many arguments.\n");
		return (1);
	}
	else if (is_formated(cmds[i]) == -1 && !EXPORTS)
	{
		ft_putstr_c(RED, "set: Variable name must begin with a letter.\n");
		return (1);
	}
	else if (is_formated(cmds[i]) == 0 && !EXPORTS)
	{
		ft_putstr_c(RED, "set: Variable name must contain ");
		ft_putstr_c(RED, "alphanumeric characters.\n");
		return (1);
	}
	else
		return (0);
}

int			builtins_set(t_list **env, char **cmds)
{
	t_list	**l_var;
	t_list	*tmp_l_var;
	int		i;

	(void)env;
	i = 1;
	__DEBUG__
	if (cmds[i] && ft_strcmp(cmds[i], "-g") == 0)
	{
		__DEBUG__
		tmp_l_var = vars_recover();
		l_var = &tmp_l_var;
		i++;
	}
	else
	{
		__DEBUG__
		l_var = &g_vars;
	}
	if (!cmds[i])
	{
		__DEBUG__
		vars_show(*l_var);
		return (0);
	}
	else if (check_variable(cmds, i) != 0)
		return (1);
	else
	{
		__DEBUG__
		if (!cmds[i + 1])
			cmds[i + 1] = ft_strdup(" ");
		__DEBUG__
		vars_add_or_modify(l_var, cmds[i], cmds[i + 1]);
		__DEBUG__
		vars_show(*l_var);
		return (0);
	}
}
