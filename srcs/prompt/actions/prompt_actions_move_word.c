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

	if (!SHIFT_RIGHT || buf != NULL)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
	return (READING);
}

t_status	action_move_last_word(char *buf)
{
	t_shell		*shell;
	t_term		*term;

	if (!SHIFT_LEFT || buf != NULL)
		return (TRYING);
	shell = recover_shell();
	term = recover_term();
	return (READING);
}
