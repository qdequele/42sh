/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 18:44:29 by qdequele         ###   ########.fr       */
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
	free_shell();
	exit(status);
}

int			builtins_exit(t_list **env, char **cmds)
{
	(void)env;
	if (!cmds[1])
		exit_shell(0);
	else if (cmds[2])
		ft_putstr_c(RED, "exit: too many arguments\n");
	else if (!is_formated(cmds[1]))
	{
		ft_putstr_c(RED, "exit: Variable name must contain ");
		ft_putstr_c(RED, "numeric characters.\n");
	}
	else
		exit_shell(ft_atoi(cmds[1]));
	return (1);
}
