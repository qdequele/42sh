/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:53:56 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_term		*recover_term(void)
{
	static t_term	term;
	return (&term);
}

int			init_term(void)
{
	char	buff[4096];
	t_term	*term;

	term = recover_term();
	if ((term->term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(buff, term->term_name) != 1)
		return (-1);
	if (tcgetattr(0, &(term->old_term)) == -1)
		return (0);
	if (tcgetattr(0, &(term->term)) == -1)
		return (0);
	term->tty = open("/dev/tty", O_RDWR);
	term->term.c_lflag &= ~(ICANON | ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(term->term)) == -1)
		return (-1);
	signal_resize_screen(0);
	return (1);
}

int			reset_term(void)
{
	t_term	*term;

	term = recover_term();
	if (tcgetattr(0, &(term->term)) == -1)
		return (-1);
	term->term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &(term->term)) == -1)
		return (-1);
	if (tcsetattr(0, 0, &(term->old_term)) == -1)
		return (-1);
	tputs(tgetstr("ve", NULL), 0, ft_tputs);
	return (1);
}