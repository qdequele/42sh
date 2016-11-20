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

void		print_shell(void)
{
	if (ft_strrchr_n(env_get(g_env, "PWD"), '/'))
	{
		ft_putstr_c(CYAN, ft_strrchr_n(env_get(g_env, "PWD"), '/'));
	}
	ft_putstr_c(CYAN, " $> ");
}

void		print_err(char *str1, char *str2)
{
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
}

void		print_tty(char *str)
{
	t_term	*term;

	term = recover_term();
	ft_putstr_fd(str, term->tty);
}

void		printendl_tty(char *str)
{
	t_term	*term;

	term = recover_term();
	ft_putendl_fd(str, term->tty);
}

int			ft_tputs(int c)
{
	t_term	*term;

	term = recover_term();
	write(term->tty, &c, 1);
	return (1);
}
