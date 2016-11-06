/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void		move_to_history(void)
{
	t_shell		*shell;
	t_prompt	*prompt;

	shell = recover_shell();
	prompt = shell->prompt;
	ft_lstdel(&shell->prompt->line, free_char);
	clean_prompt();
	if (shell->history_position < 0)
		shell->history_position = ft_lstcount(shell->history) - 1;
	else if (shell->history_position > ft_lstcount(shell->history) - 1)
		shell->history_position = 0;
	ft_putstr_fd((char*)ft_lstget_at(shell->history,
		shell->history_position)->content, recover_term()->tty);
	shell->prompt->i_position = ft_strlen((char*)ft_lstget_at(shell->history,
		shell->history_position)->content);
	string_to_list((char*)ft_lstget_at(shell->history,
		shell->history_position)->content);
}

t_status		action_history_up(char *buf)
{
	t_shell		*shell;

	shell = recover_shell();
	if (!UP)
		return (TRYING);
	if (ft_lstcount(shell->history) > 0)
	{
		shell->history_position--;
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
	if (ft_lstcount(shell->history) > 0)
	{
		shell->history_position++;
		move_to_history();
	}
	return (READING);
}
