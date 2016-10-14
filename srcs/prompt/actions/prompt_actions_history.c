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

#include <ft_sh.h>

static void		ft_move_to_history(void)
{
	t_shell		*shell;
	t_list		*tmp_list;

	shell = recover_shell();
	tmp_list = shell->history;
	ft_lstdel(shell->prompt->line, free_char);
	clean_prompt();
	if (shell->history_position < 0)
		shell->history_position = ft_lstcount(shell->history) - 1;
	else if (shell->history_position >= ft_lstcount(shell->history))
		shell->history_position = 0;
	tmp_list = ft_lstget_at(shell->history, shell->history_position);
	ft_putstr((char*)tmp_list->content);
	shell->i_position = ft_strlen((char*)tmp_list->content);
	string_to_list((char*)tmp_list->content);

}

t_status		action_history_up(char *buf)
{
	t_shell *shell;

	shell = revover_shell()
	if (!UP)
		return (TRYING);
	else if (shell->first_process == 0) 
	{
		shell->first_process++;
		shell->index_history = ft_lstcount(shell->history);
	}	
	shell->index_history--;
	move_to_history();
	return (READING);
}

t_status		action_history_down(char *buf)
{
	t_shell *shell;

	shell = recover_shell();
	if (!DOWN)
		return (TRYING);
	else if (shell->first_process == 0) 
	{
		shell->first_process++;
		shell->index_history = ft_lstcount(shell->history);
	}
	shell->index_history++;
	move_to_history();
	return (READING);
}
