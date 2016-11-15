/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/09 13:59:57 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	void	display_history(t_list *list)
{
	t_list		*cur;
	char		*tmp;
	int			i;

	i = 1;
	cur = list;
	while (cur)
	{
		ft_putnbr(i);
		ft_putstr("     ");
		if (cur->content_size != 0)
		{
			tmp = ft_strdup((char*)cur->content);
			ft_putstr_c(RED, ft_strfjoin(tmp, ft_strdup("\n")));
		}
		else
			ft_putendl_fd(cur->content, 1);
		cur = cur->next;
		i++;
	}
}

int				builtins_history(t_list **env, char **cmds)
{
	t_shell		*shell;

	(void)env;
	shell = recover_shell();
	if (cmds[1])
	{
		ft_putstr_fd("21sh : no such event: ", 2);
		ft_putstr_fd(cmds[1], 2);
		return (1);
	}
	display_history(shell->history);
	return (0);
}

char			*bultins_one_history(char *cmds)
{
	t_shell				*shell;
	t_list				*list;
	long double			i;

	shell = recover_shell();
	i = ft_atoi(&cmds[1]);
	list = shell->history;
	if ((list = ft_lst_seek(list, &cmds[1])) != NULL)
		cmds = (char*)list->content;
	else if (i == 0)
		print_error_history(i, cmds);
	else if (i < ft_lstcount(shell->history) && i > 0)
	{
		shell->history = ft_lstget_at(shell->history, (i - 1));
		cmds = (char*)shell->history->content;
	}
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
