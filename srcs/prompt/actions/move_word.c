/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_move_word.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_move_next_word(char *buf)
{
	t_shell		*shell;
	t_term		*term;
	int 		i;

	__DEBUG__
	if (!SHIFT_RIGHT)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
	i = 1;
	while (shell->prompt->i_position + i + 1 < ft_lstcount(shell->prompt->line) &&
		!(!ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line, shell->prompt->i_position + i)->content)) && 
		ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line, shell->prompt->i_position + i + 1)->content))))
	{
		i++;
	}
	while (i >= 0)
	{
		utils_move_right();
		i--;
	}
	return (READING);
}

t_status	action_move_last_word(char *buf)
{
	t_shell		*shell;
	t_term		*term;
	int 		i;

	__DEBUG__
	if (!SHIFT_LEFT)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
	i = 1;
	while (shell->prompt->i_position - i - 1 >= 0 &&
		!(!ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line, shell->prompt->i_position - i)->content)) && 
		ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line, shell->prompt->i_position - i - 1)->content))))
	{
		i++;
	}
	while (i > 0)
	{
		utils_move_left();
		i--;
	}
	return (READING);
}
