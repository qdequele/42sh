/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:54:06 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void			signal_resize_screen(int i)
{
	t_term		*term;

	UNUSED(i);
	term = recover_term();
	//TODO: Retrouver le dernier index ou etait placé l'utilisateur
	if (ioctl(0, TIOCGWINSZ, &(term->wins)) != -1)
	{
		//TODO: Replacer la personne au bon endroit
	}
}

void			signal_exit(int i)
{
	UNUSED(i);
	reset_term();
	signal(SIGQUIT, SIG_DFL);
	exit (0);
}

void			signal_background(int i)
{
	t_term	*term;
	char	cp[2];

	UNUSED(i);
	term = recover_term();
	cp[0] = term->term.c_cc[VSUSP];
	cp[1] = '\0';
	reset_term();
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void			signal_foreground(int i)
{
	UNUSED(i);
	signal(SIGTSTP, signal_handler);
	signal(SIGQUIT, signal_handler);
	init_term();
	signal_resize_screen(0);
}