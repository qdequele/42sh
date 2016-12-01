/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/08 21:20:38 by eebersol         ###   ########.fr       */
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
	char		*new_str;
	int			i;

	line = malloc((ft_lstcount(recover_shell()->prompt->line) + 1));
	i = 0;
	tmp = recover_shell()->prompt->line;
	while (tmp != NULL && i < ft_lstcount(recover_shell()->prompt->line))
	{
		car = *(char*)tmp->content;
		line[i] = car;
		tmp = tmp->next;
		i++;
	}
	line[i] = '\0';
	if (ft_strlen(line) > 0)
	{
		new_str = ft_strtrim(line);
		free(line);
		return (new_str);
	}
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
