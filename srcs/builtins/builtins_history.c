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

int	builtins_hisotry(t_list **env, char **cmds)
{
	t_shell 		*shell;

	(void)env;
	shell = recover_shell();
	if (cmds[1])
		return (0);
	ft_lstshow_x(shell->history, shell->prompt->i_position);
	return (1);
}

void	bultins_one_history(char *str)
{
	t_shell		*shell;
	t_list 		*list;
	int 		i;

	shell = recover_shell();
	list = shell->history;
	str = ft_strsub(str, 1 ,ft_strlen(str));
	i = ft_atoi(str);
	if (i > ft_lstcount(shell->history))
	{
		ft_putstr_fd("42sh : no such event: ", 2);
		ft_putnbr(i);
		ft_putchar('\n');
		return ;
	}
	list = ft_lstget_at(shell->history, i);
}
