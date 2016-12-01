/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/09 13:59:57 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	void	display_history(t_list *list)
{
	t_list		*cur;
	int			i;

	i = 1;
	cur = list;
	while (cur)
	{
		ft_putnbr(i);
		ft_putstr("     ");
		ft_putendl_fd(cur->content, 1);
		cur = cur->next;
		i++;
	}
}

int				builtins_history(t_list **env, char **cmds)
{
	t_shell		*shell;

	UNUSED(env);
	shell = recover_shell();
	if (cmds[1])
	{
		print_err("42sh : no such event: ", cmds[1]);
		return (1);
	}
	display_history(shell->history);
	return (0);
}

char			*bultins_one_history(char *cmds)
{
	t_shell				*shell;
	t_list				*list;
	int					i;

	shell = recover_shell();
	i = (int)ft_atoi(&cmds[1]);
	list = shell->history;
	if (i <= ft_lstcount(shell->history) && i > 0)
		cmds = (char*)ft_lstget_at(shell->history, (i - 1))->content;
	else if (i == 0)
		print_error_history(i, cmds);
	else if ((list = ft_lst_seek(list, &cmds[1])) != NULL)
		cmds = (char*)list->content;
	else
		print_error_history(i, cmds);
	return (cmds);
}

static void		history_free_one(void *elem, size_t size)
{
	char		*str;

	UNUSED(size);
	str = elem;
	if (str)
	{
		free(str);
	}
}

void			history_free(t_list **l_history)
{
	ft_lstdel(l_history, &history_free_one);
}
