/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_to_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/14 16:54:05 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*action_seek_to_history(char *cmds)
{
	t_shell		*shell;
	t_list		*cur;
	char		*str;
	int			i;

	shell = recover_shell();
	cur = shell->history;
	str = &cmds[1];
	i = ft_atoi(str);
	if (ft_isdigit(str[0]) && i < ft_lstcount(shell->history) && i > 0)
		str = (char*)ft_lstget_at(shell->history, (i - 1))->content;
	else if ((cur = ft_lst_seek(shell->history, str)) != NULL)
		str = (char*)cur->content;
	else
	{
		print_err("42sh : no such event: ", str);
		return (NULL);
	}
	ft_lstdel(&shell->prompt->line, free_char);
	string_to_list(str);
	return (str);
}
