/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 21:26:29 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void			string_to_list(char *str)
{
	t_shell		*shell;
	char		*dst;
	size_t		i;

	shell = recover_shell();
	i = 0;
	while (i < ft_strlen(str))
	{
		dst = ft_strnew(1);
		dst[0] = str[i];
		ft_lstadd(&shell->prompt->line,
			ft_lstnew(dst, (sizeof(char))));
		ft_strdel(&dst);
		i++;
	}
	shell->prompt->line = ft_lst_reverse(shell->prompt->line);
}

char			*list_to_string(void)
{
	char		*line;
	char		car;
	t_list		*tmp;
	int			i;
	t_shell		*shell;

	shell = recover_shell();
	line = (char*)malloc(sizeof(char) * (ft_lstcount(shell->prompt->line) + 1));
	i = 0;
	tmp = shell->prompt->line;
	while (tmp != NULL && i < ft_lstcount(shell->prompt->line))
	{
		car = *(char*)tmp->content;
		line[i] = car;
		tmp = tmp->next;
		i++;
	}
	line[i] = '\0';
	if (ft_strlen(line) > 0)
		return (ft_strtrim(line));
	else
		return (line);
}

char			**list_to_tab(t_list *list)
{
	int			i;
	char		**tab_var;

	tab_var = (char**)malloc(sizeof(char*) * (ft_lstcount(list) + 1));
	list = ft_lst_reverse(list);
	i = 0;
	while (list != NULL)
	{
		tab_var[i] = (char*)list->content;
		list = list->next;
		i++;
	}
	tab_var[i] = NULL;
	return (tab_var);
}
