/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 21:07:39 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	print_shell(void)
{
	if (ft_strrchr_n(env_get(g_env, "PWD"), '/'))
	{
		ft_putstr_c(CYAN, ft_strrchr_n(env_get(g_env, "PWD"), '/'));
	}
	ft_putstr_c(CYAN, " $> ");
}

void	print_shell_err(char *s)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\e[0m", 2);
}
