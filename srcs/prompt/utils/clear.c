/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/18 16:10:44 by qdequele         ###   ########.fr       */
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
	exit(0);
}
