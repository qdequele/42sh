/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/09 13:57:05 by qdequele         ###   ########.fr       */
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
	(void)env;
	if (!cmds[1])
		exit_shell(ft_atoi(vars_get(g_vars, "?")));
	else if (cmds[2])
		print_err("exit: too many arguments", "");
	else if (!is_formated(cmds[1]))
	{
		print_err("exit: Variable name must contain ", "numeric characters.");
	}
	else
		exit_shell(ft_atoi(cmds[1]));
	return (1);
}
