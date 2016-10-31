/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 12:02:26 by qdequele         ###   ########.fr       */
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
		action_move_max_top,
		action_move_max_bottom,
		action_ignore_input,
		action_insert_char
	};
	return ((void *)f);
}

void		*get_actions_copy(void)
{
	static t_status (*f[])(char *) = {
		action_move_right,
		action_move_left,
		action_exec_cmd,
		action_paste,
		action_copy,
		action_cut,
		action_copy_quit
	};
	return ((void *)f);
}