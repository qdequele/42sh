/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/30 13:48:53 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	clean_prompt(void)
{
	t_shell	*shell;

	shell = recover_shell();
	while((size_t)shell->prompt->i_position < ft_lstcount(shell->prompt->line) - ft_strlen(shell->prompt->str_cpy))
	{
		utils_move_right();
	}
	while (shell->prompt->i_position > 0)
	{
		tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
		utils_move_left();
	}
	tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
}

void 	clean_last_x_char(int i)
{
	t_shell	*shell;

	shell = recover_shell();
	while(shell->prompt->i_position < ft_lstcount(shell->prompt->line))
	{
		utils_move_right();
	}
	while (shell->prompt->i_position > 0 && i > 0)
	{
		ft_console("erase i :%d\n", i);
		delete_one_char();
		tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
		utils_move_left();
		i--;
	}
	// utils_move_right();
	delete_one_char();
	tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
}
