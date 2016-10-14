/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_find.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void		*get_actions_list(void)
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
		action_history_down,
		action_move_max_top,
		action_move_max_bottom,
		action_ignore_input,
		action_shell_quit,
		action_insert_char
	};

	return ((void *)f);
}

t_status		prompt_find_function(char *buf)
{
	t_status	(**actions)(char *);
	t_status	status;

	actions = get_actions_list();
	status = TRYING;
	while (*actions && status == TRYING)
	{
		status = (*actions)(buf);
		actions++;
	}
	return (status);
}