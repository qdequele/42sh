/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/20 20:27:11 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_term		*recover_term(void)
{
	static t_term	term;

	return (&term);
}

int			init_term(int save)
{
	t_term	*term;
	char	bf_env[4096];

	term = recover_term();
	if (!isatty(term->tty))
		return (0);
	if (save && tcgetattr(0, &(term->old_term)) == -1)
		return (0);
	if ((term->term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(bf_env, term->term_name) != 1)
		return (-1);
	if (tcgetattr(0, &(term->term)) == -1)
		return (0);
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
	if (!isatty(term->tty))
		return (0);
	tputs(tgetstr("ve", NULL), 1, ft_tputs);
	if (tcsetattr(0, 0, &(term->old_term)) == -1)
		return (-1);
	return (1);
}
