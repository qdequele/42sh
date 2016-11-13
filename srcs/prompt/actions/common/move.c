/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_move_up(char *b)
{
	if (!S_UP)
		return (TRYING);
	utils_move_up();
	return (READING);
}

t_status	action_move_down(char *b)
{
	if (!S_DOWN)
		return (TRYING);
	utils_move_down();
	return (READING);
}

t_status	action_move_left(char *b)
{
	if (!LEFT)
		return (TRYING);
	utils_move_left();
	return (READING);
}

t_status	action_move_right(char *b)
{
	if (!RIGHT)
		return (TRYING);
	utils_move_right();
	return (READING);
}
