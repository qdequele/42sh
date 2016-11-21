/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/08 20:58:32 by qdequele         ###   ########.fr       */
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
	shell->history_index = 0;
	shell->last_exit_code = -1;
	shell->prompt = NULL;
	shell->mode = NORMAL;
	shell->posibilities = NULL;
	shell->autocomplete_position = 0;
	shell->signals_disabled = 0;
	shell->jobs = NULL;
}

void		free_shell(void)
{
	t_shell		*shell;

	shell = recover_shell();
	save_history();
	save_vars();
	env_free(&g_env);
	env_free(&g_export);
	vars_free(&g_l_vars);
	vars_free(&g_g_vars);
	free_jobs(&(shell->jobs));
	history_free(&(shell->history));
}
