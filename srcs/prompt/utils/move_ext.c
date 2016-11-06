/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 12:16:45 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	utils_move_start(void)
{
	t_shell		*shell;

	shell = recover_shell();
	while (shell->prompt->i_position >= 0)
		utils_move_left();
	shell->prompt->i_position--;
	tputs(tgoto(LESTR, 0, 0), 0, ft_tputs);
}

void	utils_move_end(void)
{
	t_shell		*shell;

	shell = recover_shell();
	while (shell->prompt->i_position < ft_lstcount(shell->prompt->line))
		utils_move_right();
	tputs(tgoto(RISTR, 0, 1), 0, ft_tputs);
}

void	utils_move_max_top(void)
{
	t_shell		*shell;

	shell = recover_shell();
	while (shell->prompt->p_length + shell->prompt->i_position > term->wins.ws_col)
		utils_move_up();
}

void	utils_move_max_bottom(void)
{
	t_shell		*shell;

	shell = recover_shell();
}

