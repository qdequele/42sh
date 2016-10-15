/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/15 17:34:38 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void    utils_move_up(void)
{
	t_shell		*shell;
	t_term		*term;

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
}

void    utils_move_down(void)
{
	t_shell		*shell;
	t_term		*term;
	int			delta;

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
}

void    utils_move_left(void)
{
	t_shell		*shell;

	shell = recover_shell();
	if(shell->prompt->i_position > 0)
	{
		shell->prompt->i_position--;
		tputs(tgoto(LESTR, 0, 0), 0, ft_tputs);
	}
}

void    utils_move_right(void)
{
	t_shell		*shell;
	t_term		*term;

	shell = recover_shell();
	term = recover_term();
	if(shell->prompt->i_position < shell->prompt->l_length)
	{
		shell->prompt->i_position++;
		if ((shell->prompt->i_position + shell->prompt->p_length - 1) % term->wins.ws_col == 0){
			tputs(tgoto(DOSTR, 0, 0), 0, ft_tputs);
			tputs(tgoto(CRSTR, 0, 0), 0, ft_tputs);
		}
		else {
            tputs(tgoto(RISTR, 0, 0), 0, ft_tputs);
        }
	}
}