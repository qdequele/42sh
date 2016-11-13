/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 18:52:25 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void		move_to_history(void)
{
	t_shell		*shell;
	int			pos;

	shell = recover_shell();
	pos = ft_lstcount(shell->history) - 1 - shell->history_position;
	if (shell->history_position >= 0 &&
		shell->history_position <= (ft_lstcount(shell->history) - 1))
	{
		ft_lstdel(&shell->prompt->line, free_char);
		clean_prompt();
		ft_putstr_fd((char*)ft_lstget_at(shell->history,
			pos)->content, recover_term()->tty);
		shell->prompt->i_position = ft_strlen((char*)ft_lstget_at(
			shell->history, pos)->content);
		string_to_list((char*)ft_lstget_at(shell->history,
			pos)->content);
	}
}

t_status		action_history_up(char *buf)
{
	t_shell		*shell;

	shell = recover_shell();
	if (!UP)
		return (TRYING);
	if (ft_lstcount(shell->history) > 0 && shell->history_position <
		ft_lstcount(shell->history) - 1)
	{
		shell->history_position++;
		move_to_history();
	}
	return (READING);
}

t_status		action_history_down(char *buf)
{
	t_shell *shell;

	shell = recover_shell();
	if (!DOWN)
		return (TRYING);
	if (ft_lstcount(shell->history) > 0 && shell->history_position > 0)
	{
		shell->history_position--;
		move_to_history();
	}
	return (READING);
}
