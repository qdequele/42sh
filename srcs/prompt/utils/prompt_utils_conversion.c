/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils_conversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/17 14:34:14 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	string_to_list(char *str)
{
	t_shell		*shell;
	char		*dst;
	size_t		i;

	shell = recover_shell();
	i = 0;
	while (i < ft_strlen(str))
	{
		dst = ft_strnew(ft_strlen(str));
		dst[0] = str[i];
		ft_lstadd(&shell->prompt->line,
			ft_lstnew(dst, (sizeof(char*) * ft_strlen(dst))));
		ft_strdel(&dst);
		i++;
	}
	ft_lst_reverse(shell->prompt->line);
	str[i] = '\0';
}

char	*list_to_string(void)
{
	char		*line;
	char		*car;
	t_list		*tmp;
	int			i;
	t_shell		*shell;
	t_prompt	*prompt;

	shell = recover_shell();
	prompt = shell->prompt;
	line = (char*)malloc(sizeof(char) * (prompt->l_length + 1));
	line[prompt->l_length] = '\0';
	i = 0;
	tmp = prompt->line;
	while (tmp != NULL && i <= prompt->l_length)
	{
		car = (char*)tmp->content;
		line[i] = car[0];
		tmp = tmp->next;
		i++;
	}
	return (line);
}