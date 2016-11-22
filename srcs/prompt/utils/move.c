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

void	utils_move_up(void)
{
	t_shell		*shell;
	t_term		*term;
	int			i;
	int			pos;

	shell = recover_shell();
	term = recover_term();
	i = 0;
	pos = shell->prompt->i_pos - shell->prompt->p_pos;
	while (i < term->wins.ws_col && pos >= 0)
	{
		pos = shell->prompt->i_pos - shell->prompt->p_pos;
		utils_move_left();
		i++;
	}
}

void	utils_move_down(void)
{
	t_shell		*shell;
	t_term		*term;
	int			i;

	shell = recover_shell();
	term = recover_term();
	i = 0;
	while (i < term->wins.ws_col
	&& shell->prompt->i_pos < ft_lstcount(shell->prompt->line))
	{
		utils_move_right();
		i++;
	}
}

void	utils_move_left(void)
{
	t_shell		*shell;
	int			pos;

	shell = recover_shell();
	pos = shell->prompt->i_pos - shell->prompt->p_pos;
	if (pos > 0)
	{
		shell->prompt->i_pos--;
		tputs(tgoto(LESTR, 0, 0), 0, ft_tputs);
	}
}

void	utils_move_right(void)
{
	t_shell		*shell;
	t_term		*term;
	int			pos;

	shell = recover_shell();
	term = recover_term();
	pos = shell->prompt->i_pos - shell->prompt->p_pos;
	if (shell->prompt->i_pos < ft_lstcount(shell->prompt->line))
	{
		shell->prompt->i_pos++;
		tputs(tgoto(RISTR, 0, 0), 0, ft_tputs);
		pos = shell->prompt->i_pos - shell->prompt->p_pos;
		if ((pos + shell->prompt->p_length)
			% term->wins.ws_col == 0)
		{
			tputs(tgoto(DOSTR, 0, 0), 0, ft_tputs);
			tputs(tgoto(CRSTR, 0, 0), 0, ft_tputs);
		}
	}
}
