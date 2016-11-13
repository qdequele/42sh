/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void		*get_actions_normal(void)
{
	static t_status (*f[])(char *) = {
		action_move_next_word,
		action_move_last_word,
		action_move_up,
		action_move_down,
		action_move_right,
		action_move_left,
		action_move_start,
		action_move_end,
		action_delete_char,
		action_delete_next_char,
		action_exec_cmd,
		action_history_up,
		action_autocomplete,
		action_history_down,
		action_ignore_input,
		action_quit,
		action_insert_char
	};

	return ((void *)f);
}

void		*get_actions_copy(void)
{
	static t_status (*f[])(char *) = {
		action_move_right,
		action_move_left,
		action_move_next_word,
		action_move_last_word,
		action_move_start,
		action_move_end,
		action_move_up,
		action_move_down,
		action_exec_cmd,
		action_paste,
		action_copy,
		action_cut,
		action_free,
		action_copy_quit
	};

	return ((void *)f);
}

void		*get_actions_heredoc(void)
{
	static t_status (*f[])(char *) = {
		action_move_right,
		action_move_left,
		action_move_next_word,
		action_move_last_word,
		action_move_start,
		action_move_end,
		action_move_up,
		action_move_down
	};

	return ((void *)f);
}

void		*get_actions_quote(void)
{
	static t_status (*f[])(char *) = {
		action_move_right,
		action_move_left,
		action_move_next_word,
		action_move_last_word,
		action_move_start,
		action_move_end,
		action_move_up,
		action_move_down,
		action_delete_char,
		action_delete_next_char,
		action_exec_cmd,
		action_insert_char
	};

	return ((void *)f);
}

t_status	prompt_find_function(char *buf)
{
	t_status	(**actions)(char *);
	t_status	status;
	t_shell		*shell;

	shell = recover_shell();
	if (shell->mode == QUOTE)
		actions = get_actions_quote();
	if (shell->mode == HEREDOC)
		actions = get_actions_heredoc();
	if (shell->mode == COPY)
		actions = get_actions_copy();
	else
		actions = get_actions_normal();
	status = TRYING;
	while (*actions && status == TRYING)
	{
		status = (*actions)(buf);
		actions++;
	}
	return (status);
}
