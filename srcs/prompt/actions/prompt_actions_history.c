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

#include <42shell.h>

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




void			ft_move_to_history(void)
{
	t_shell		*shell;
	t_prompt	*prompt;
	t_list		*tmp_list;

	shell = ft_shell();
	prompt = shell->prompt;
	tmp_list = prompt->history;
	ft_lstdel(prompt->line, free_char);
	ft_clean_prompt();
	if (prompt->history_position < 0)
		prompt->history_position = ft_lstlen(prompt->history) - 1;
	else if (prompt->history_position >= ft_lstlen(prompt->history))
		prompt->history_position = 0;
	tmp_list = ft_lstget_at(prompt->history, prompt->history_position);
	ft_putstr((char*)tmp_list->content);
	prompt->x = ft_strlen((char*)tmp_list->content);
	ft_string_to_lchar((char*)tmp_list->content);
}
