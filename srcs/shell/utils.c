/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 18:18:01 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void			reset_autocomplete_possibilities(void)
{
	t_shell		*shell;

	shell = recover_shell();
	shell->autocomplete_position = 0;
	ft_lstdel(&(shell->posibilities), free_char);
}

void			free_input(void)
{
	t_shell		*shell;

	shell = recover_shell();
	ft_lstdel(&(shell->prompt->line), &free_char);
}

void			add_history(char *line)
{
	t_shell		*shell;

	shell = recover_shell();
	if (line[0] == '!')
		return ;
	ft_lstadd_at(&shell->history,
		ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1),
		shell->history_index);
	shell->history_index++;
}
