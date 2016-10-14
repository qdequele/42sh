/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_move_ext.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:49:56 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

t_status	action_move_start(char *buf)
{
	t_shell		*shell;
	t_term		*term;

	if (!HOME || !FN_LEFT)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
    while (shell->prompt->i_position > 0)
	{
		action_move_left(NULL);
	}
	return (READING);
}

t_status	action_move_end(char *buf)
{
	t_shell		*shell;
	t_term		*term;

	if (!END || !FN_RIGHT)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
    while (shell->prompt->i_position < shell->prompt->l_length)
	{
		action_move_right(NULL);
	}
	return (READING);
}

t_status	action_move_max_top(char *buf)
{
	t_shell		*shell;
	t_term		*term;

	if (!SHIFT_MAJ_UP)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
    while (shell->prompt->p_length + shell->prompt->i_position > term->wins.ws_col)
	{
		tputs(tgoto(UPSTR, 0, 0), 0, ft_tputs);
		shell->prompt->i_position -= term->wins.ws_col;
		if (shell->prompt->i_position < 0)
		{
			shell->prompt->i_position = 0;
			tputs(tgoto(CRSTR, 0, 0), 0, ft_tputs);
			tputs(tgoto(RISTR, 0, shell->prompt->p_length), 0, ft_tputs);
		}
	}
	return (READING);
}

t_status	action_move_max_bottom(char *buf)
{
	t_shell		*shell;
	t_term		*term;

	if (!SHIFT_MAJ_DOWN)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
    ft_putchar_fd('#', term->tty);
	return (READING);
}

