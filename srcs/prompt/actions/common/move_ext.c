/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 12:10:11 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_move_start(char *b)
{
	if (!HOME || !FN_LEFT)
		return (TRYING);
	utils_move_start();
	return (READING);
}

t_status	action_move_end(char *b)
{
	if (!END || !FN_RIGHT)
		return (TRYING);
	utils_move_end();
	return (READING);
}

t_status	action_move_next_word(char *b)
{
	t_shell		*shell;
	int			i;

	if (!S_RIGHT)
		return (TRYING);
	shell = recover_shell();
	i = 1;
	while (shell->prompt->i_pos + i + 1 < ft_lstcount(shell->prompt->line)
		&& !(!ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line,
			shell->prompt->i_pos + i)->content))
		&& ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line,
			shell->prompt->i_pos + i + 1)->content))))
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

t_status	action_move_last_word(char *b)
{
	t_shell		*shell;
	int			i;

	if (!S_LEFT)
		return (TRYING);
	shell = recover_shell();
	i = 1;
	while (shell->prompt->i_pos - i - 1 >= 0
		&& !(!ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line,
			shell->prompt->i_pos - i)->content))
		&& ft_isspace(*(char *)(ft_lstget_at(shell->prompt->line,
			shell->prompt->i_pos - i - 1)->content))))
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
