/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/20 21:46:09 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	is_formated(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_shell(int status)
{
	recover_shell()->last_exit_code = status;
}

int			builtins_exit(t_list **env, char **cmds)
{
	UNUSED(env);
	if (!cmds[1])
		exit_shell(ft_atoi(vars_get(g_l_vars, "?")));
	else if (cmds[2])
	{
		vars_add_or_modify(&g_l_vars, "?", "1");
		print_err("exit: too many arguments", "");
	}
	else if (!is_formated(cmds[1]))
	{
		vars_add_or_modify(&g_l_vars, "?", "1");
		print_err("exit: numeric argument required", "");
		exit_shell(1);
	}
	else
	{
		exit_shell(ft_atoi(cmds[1]));
	}
	return (1);
}
