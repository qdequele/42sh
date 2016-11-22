/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils_show-end-of-line.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/24 13:53:34 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	print_eol(void)
{
	t_shell		*shell;
	int			index;
	void		*tmp;
	int			i;
	char		*string;

	shell = recover_shell();
	index = shell->prompt->i_pos;
	i = 0;
	string = (char *)malloc(sizeof(char) *
						(ft_lstcount(shell->prompt->line) - index + 2));
	while (index + i < ft_lstcount(shell->prompt->line))
	{
		tmp = ft_lstget_at(shell->prompt->line, index + i)->content;
		string[i] = *(char*)tmp;
		i++;
	}
	string[i] = ' ';
	string[++i] = '\0';
	write(recover_term()->tty, string, i);
	shell->prompt->i_pos += i;
	free(string);
	while (--i >= 0)
		utils_move_left();
}
