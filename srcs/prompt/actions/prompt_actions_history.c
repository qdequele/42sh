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

#include <21sh.h>

t_status	action_history_up(char *buf)
{
	if (!UP)
		return (TRYING);
	return (READING);
}

t_status	action_history_down(char *buf)
{
	if (!DOWN)
		return (TRYING);
	return (READING);
}