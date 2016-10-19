/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_seek_to_history.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:54:05 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char 	*action_seek_to_history(char *cmds)
{
	t_shell 	*shell;
	t_term 		*term;
	t_list 		*cur;
	char 		*str;

	shell = recover_shell();
	term = recover_term();
	str = ft_strsub(cmds, 1 ,ft_strlen(cmds));
	cur = shell->history;
	shell->history = ft_lst_reverse(shell->history);
	if (ft_isdigit(str[0]) == 1 && ft_atoi(str) < ft_lstcount(shell->history) && ft_atoi(str) > 0)
	{
		cur = ft_lstget_at(shell->history, ft_atoi(str));
		str = (char*)cur->content;
	}
	else if ((cur = ft_lst_seek(shell->history, str)) != NULL)
		str = (char*)cur->content;
	else
	{
		ft_putstr_fd("42sh : no such event: ", 2);
		ft_putendl_fd(str, 2);
		return (NULL);
	}	
	ft_putendl_fd(str, term->tty);
	return (str);
}
