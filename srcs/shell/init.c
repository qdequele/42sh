/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/18 16:19:50 by qdequele         ###   ########.fr       */
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
	shell = (t_shell*)malloc(sizeof(t_shell));
	shell->history = NULL;
	shell->history_position = 0;
	shell->last_exit_code = 0;
	shell->prompt = NULL;
	shell->mode = NORMAL;
}