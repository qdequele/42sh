/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status action_move_up(char *buf)
{
	t_shell		*shell;
	t_term		*term;

	if (!SHIFT_UP )
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
	if (shell->prompt->p_length + shell->prompt->i_position > term->wins.ws_col)
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

t_status action_move_down(char *buf)
{
	t_shell		*shell;
	t_term		*term;
	int			delta;

	if (!SHIFT_DOWN )
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
	if (shell->prompt->i_position + term->wins.ws_col <= shell->prompt->l_length)
	{
		tputs(tgoto(DOSTR, 0, 0), 0, ft_tputs);
		shell->prompt->i_position += term->wins.ws_col;
	}
	else
	{
		delta = (shell->prompt->p_length + shell->prompt->l_length)
			% term->wins.ws_col;
		tputs(tgoto(DOSTR, 0, 0), 0, ft_tputs);
		tputs(tgoto(CRSTR, 0, 0), 0, ft_tputs);
		tputs(tgoto(RISTR, 0, delta), 0, ft_tputs);
		shell->prompt->i_position = shell->prompt->l_length;
	}
	return (READING);
}

t_status action_move_left(char *buf)
{
	t_shell		*shell;

	if (!LEFT )
		return (TRYING);
	shell = recover_shell();
	if(shell->prompt->i_position > 0)
	{
		shell->prompt->i_position--;
		tputs(tgoto(LESTR, 0, 0), 0, ft_tputs);
	}
	return (READING);
}

t_status action_move_right(char *buf)
{
	t_shell		*shell;
	t_term		*term;

	if (!RIGHT )
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
	if(shell->prompt->i_position < shell->prompt->l_length)
	{
		shell->prompt->i_position++;
		if ((shell->prompt->i_position + shell->prompt->p_length - 1) % term->wins.ws_col == 0){
			tputs(tgoto(DOSTR, 0, 0), 0, ft_tputs);
			tputs(tgoto(CRSTR, 0, 0), 0, ft_tputs);
		}
		else
			tputs(tgoto(RISTR, 0, 0), 0, ft_tputs);
	}
	return (READING);
}