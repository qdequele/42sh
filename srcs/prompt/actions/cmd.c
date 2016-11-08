/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/08 20:53:00 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_exec_cmd(char *buf)
{
	if (!ENTER)
		return (TRYING);
	utils_move_end();
	ft_putchar('\n');
	return (FOUND);
}

t_status	action_ignore_input(char *buf)
{
	if (!IGNORE_1)
		return (TRYING);
	return (READING);
}

t_status	action_quit(char *buf)
{
	t_shell	*shell;

	if (!CTRL_D)
		return (TRYING);
	shell = recover_shell();
	if (ft_lstcount(shell->prompt->line) > 0)
		clean_last_x_char(ft_lstcount(shell->prompt->line));
	else
	{
		free_input();
		free_shell();
		shell->last_exit_code = 0;
	}
	return (READING);
}
