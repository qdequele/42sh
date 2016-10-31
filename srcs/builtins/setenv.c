/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:33:00 by qdequele         ###   ########.fr       */
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

int			builtins_setenv(t_list **env, char **cmds)
{
	// printf("cmds[1] : [%s] cmds[2] ; [%s]\n", cmds[1], cmds[2]);
	if (!cmds[1])
	{
		env_show(*env);
		return (0);
	}
	else if (cmds[3])
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
	else
	{
		if (!cmds[2])
			cmds[2] = ft_strdup(" ");
		env_add_or_modify(env, cmds[1], cmds[2]);
		return (0);
	}
}
