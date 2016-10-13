/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/12 16:16:04 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

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