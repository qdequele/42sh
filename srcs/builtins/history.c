/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/21 15:01:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	void	display_history(t_list *list)
{
	t_list	*cur;
	int		i;

	cur = list;
	i = 1;
	while (cur)
	{
		ft_putnbr(i);
		ft_putstr("     ");
		if (cur->content_size != 0)
			ft_putstr_c(RED, ft_strjoin(cur->content, "\n"));
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
		ft_putstr_fd("42sh : no such event: ", 2);
		ft_putstr_fd(cmds[1], 2);
		return (1);
	}
	display_history(shell->history);
	return (0);
}

void			bultins_one_history(char *cmds)
{
	t_shell		*shell;
	char		*str;
	int			i;

	shell = recover_shell();
	i = ft_atoi(ft_strsub(cmds, 1, ft_strlen(cmds)));
	str = ft_strsub(cmds, 1, ft_strlen(cmds));
	if ((shell->history = ft_lst_seek(shell->history, str)) != NULL)
		(void)str;
	else
	{
		ft_putstr_fd("42sh : no such event: ", 2);
		ft_putstr_fd(cmds, 2);
		ft_putchar('\n');
		return ;
	}
	if (i < ft_lstcount(shell->history) && i > 0)
		shell->history = ft_lstget_at(shell->history, i);
	else
	{
		ft_putstr_fd("42sh : no such event: ", 2);
		ft_putnbr(i);
		ft_putchar('\n');
	}
}
