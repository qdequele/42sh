/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:54:06 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	signal_handler(int i)
{
	if (i == SIGINT || i == SIGQUIT || i == SIGKILL || i == SIGSTOP)
		signal_exit(i);
	else if (i == SIGTSTP)
		signal_background(i);
	else if (i == SIGCONT)
		signal_foreground(i);
	else if (i == SIGWINCH)
		signal_resize_screen(i);
	i = 0;
}

void	init_signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGWINCH, signal_handler);
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
