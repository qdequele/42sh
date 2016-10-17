/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_history.c                            :+:      :+:    :+:   */
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
	t_term		*term;
	t_prompt	*prompt;
	t_list		*tmp_list;

	shell = recover_shell();
	term = recover_term();
	prompt = shell->prompt;
	tmp_list = shell->history;
	if (prompt->line)
		clean_prompt();
	if (shell->history_position < 0)
		shell->history_position = ft_lstcount(shell->history) - 1;
	else if (shell->history_position > ft_lstcount(shell->history) - 1)
		shell->history_position = 0;
	tmp_list = ft_lstget_at(shell->history, shell->history_position);
	ft_putstr_fd((char*)tmp_list->content, term->tty);
	shell->prompt->i_position = ft_strlen((char*)tmp_list->content) + 1;
	string_to_list((char*)tmp_list->content);

}

t_status		action_history_up(char *buf)
{
	t_shell 	*shell;

	shell = recover_shell();
	if (!UP)
		return (TRYING);
	if (ft_lstcount(shell->history) > 0)
	{
		move_to_history();
		shell->history_position++;
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
		move_to_history();
		shell->history_position--;
	}
	return (READING);
}
