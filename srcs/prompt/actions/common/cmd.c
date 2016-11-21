/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/09 14:13:37 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_exec_cmd(char *b)
{
	if (!ENTER)
		return (TRYING);
	utils_move_end();
	ft_putchar('\n');
	return (FOUND);
}

t_status	action_ignore_input(char *b)
{
	if (!IGNORE_1)
		return (TRYING);
	return (READING);
}

t_status	action_quit(char *b)
{
	t_shell	*shell;

	if (!CTRL_D)
		return (TRYING);
	shell = recover_shell();
	if (ft_lstcount(shell->prompt->line) == 0)
	{
		shell->last_exit_code = ft_atoi(vars_get(g_l_vars, "?"));
		return (FOUND);
	}
	return (READING);
}

t_status	action_clear(char *b)
{
	t_shell	*shell;

	if (!CTRL_L)
		return (TRYING);
	shell = recover_shell();
	if (ft_lstcount(shell->prompt->line) == 0)
	{
		tputs(CLSTR, 0, ft_tputs);
		return (FOUND);
	}
	return (READING);
}
