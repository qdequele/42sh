/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/09 14:07:22 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	signal_resize_screen(int i)
{
	t_term	*term;

	UNUSED(i);
	term = recover_term();
	ioctl(0, TIOCGWINSZ, &term->wins);
}

void	signal_reprompt(int i)
{
	t_shell	*shell;

	UNUSED(i);
	shell = recover_shell();
	if (ft_lstcount(shell->prompt->line) > 0)
		clean_last_x_char(ft_lstcount(shell->prompt->line));
	else
	{
		ft_putendl("");
		print_shell();
	}
}

void	ignore_major_signals(void)
{
	signal(SIGWINCH, signal_resize_screen);
	signal(SIGINT, signal_reprompt);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
}

void	reset_major_signals(void)
{
	signal(SIGWINCH, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
}
