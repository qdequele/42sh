/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 20:02:50 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	int	is_formated(char *str)
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

static	int	is_error(char **cmds)
{
	if (cmds[2] && cmds[2] && cmds[3])
	{
		ft_putstr_c(RED, "setenv: Too many arguments.\n");
		return (1);
	}
	else if (is_formated(cmds[1]) == -1 && !EXPORTS)
	{
		ft_putstr_c(RED, "setenv: Variable name must begin with a letter.\n");
		return (1);
	}
	else if (is_formated(cmds[1]) == 0 && !EXPORTS)
	{
		ft_putstr_c(RED, "setenv: Variable name must contain ");
		ft_putstr_c(RED, "alphanumeric characters.\n");
		return (1);
	}
	return (0);
}

int			builtins_setenv(t_list **env, char **cmds)
{
	if (!cmds[1])
	{
		env_show(*env);
		return (0);
	}
	if (is_error(cmds))
		return (1);
	else
	{
		if (!cmds[2])
			env_add_or_modify(env, cmds[1], "");
		else
			env_add_or_modify(env, cmds[1], cmds[2]);
		return (0);
	}
}
