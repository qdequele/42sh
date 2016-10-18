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

t_status		prompt_find_function(char *buf)
{
	t_status	(**actions)(char *);
	t_status	status;
	t_shell		*shell;

	shell = recover_shell();
	if (shell->mode == COPY)
		actions = get_actions_copy();
	else if (shell->mode == HISTORY)
		actions = get_actions_history();
	else if (shell->mode == AUTOCOMPLETE)
		actions = get_actions_autocomplete();
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