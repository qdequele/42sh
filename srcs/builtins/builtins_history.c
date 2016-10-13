/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

static	void	display_history(t_list *list)
{
	t_list	*cur;
	int		i;

	cur = list;
	i = 0;
	while (cur)
	{
		ft_putnbr(i);
		ft_putstr("     ");
		ft_putendl_fd(cur->content, 1);
		cur = cur->next;
		i++;
	}
}

int			builtins_history(t_list **env, char **cmds)
{
	t_shell 		*shell;

	(void)env;
	shell = recover_shell();
	if (cmds[1])
	{
		ft_putstr_fd("42sh : no such event: ", 2);
		ft_putstr_fd(cmds[1], 2);
		return (0);
	}
	shell->history = ft_lst_reverse(shell->history);
	display_history(shell->history);
	return (1);
}

void		bultins_one_history(char *cmds)
{
	t_shell		*shell;
	int 		i;

	shell = recover_shell();
	i = ft_atoi(ft_strsub(cmds, 1, ft_strlen(cmds)));
	if ((shell->history = ft_lst_seek(shell->history, ft_strsub(cmds, 1, ft_strlen(cmds)))) != NULL)
	{
		cmds = ft_strjoin("!", (char*)shell->history);
		// remplacer le prompt actuel par cmds[0]
	}
	else
	{
		if (i < ft_lstcount(shell->history) && i > 0)
		{
			shell->history = ft_lstget_at(shell->history, i);
			// remplacer le prompt actuel par (char*)shell->history->content;
		}
		else
		{
			ft_putstr_fd("42sh : no such event: ", 2);
			ft_putnbr(i);
			ft_putchar('\n');
		}
	}
}
