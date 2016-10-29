/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/29 15:15:18 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void    utils_move_up(void)
{
	t_shell		*shell;
	t_term		*term;
	int 		i;

	shell = recover_shell();
	term = recover_term();
	i = 0;
	while (i < term->wins.ws_col && shell->prompt->i_position >= 0)
	{
		utils_move_left();
		i++;
	}
}

void    utils_move_down(void)
{
	t_shell		*shell;
	t_term		*term;
	int 		i;

	shell = recover_shell();
	term = recover_term();
	i = 0;
	while (i < term->wins.ws_col
	&& shell->prompt->i_position < ft_lstcount(shell->prompt->line))
	{
		utils_move_right();
		i++;
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
	if(shell->prompt->i_position < ft_lstcount(shell->prompt->line))
	{
		shell->prompt->i_position++;
		if ((shell->prompt->i_position + shell->prompt->p_length)
			% term->wins.ws_col == 0)
		{
			tputs(tgoto(DOSTR, 0, 0), 0, ft_tputs);
			tputs(tgoto(CRSTR, 0, 0), 0, ft_tputs);
		}
		else
		{
            tputs(tgoto(RISTR, 0, 0), 0, ft_tputs);
        }
	}
}
