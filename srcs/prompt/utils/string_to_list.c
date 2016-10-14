/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
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
