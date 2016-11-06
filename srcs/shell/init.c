/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 18:28:29 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_shell		*recover_shell(void)
{
	static t_shell	shell;
	return (&shell);
}

void		init_shell(void)
{
	t_shell		*shell;

	shell = recover_shell();
	shell->history = NULL;
	shell->history_position = -1;
	shell->last_exit_code = 0;
	shell->prompt = NULL;
	shell->mode = NORMAL;
	shell->posibilities = NULL;
	shell->autocomplete_position = 0;
	shell->signals_disabled = 0;
	shell->jobs = NULL;
}
