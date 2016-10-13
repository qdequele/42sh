/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/12 16:15:53 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

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

int			builtins_exit(t_list **env, char **cmds)
{
	(void)env;
	if (!cmds[1])
		exit(0);
	else if (cmds[2])
		ft_putstr_c(RED, "exit: too many arguments\n");
	else if (!is_formated(cmds[1]))
	{
		ft_putstr_c(RED, "exit: Variable name must contain ");
		ft_putstr_c(RED, "numeric characters.\n");
	}
	else
		exit(ft_atoi(cmds[1]));
	return (1);
}
