/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 19:12:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	put_specific_char(char c, int fd)
{
	if (c == '|' || c == '&' || c == ';')
		ft_putchar_fd_c(YELLOW, c, fd);
	else if (c == '"')
		ft_putchar_fd_c(RED, c, fd);
	else if (c == '\'')
		ft_putchar_fd_c(LIGHT_RED, c, fd);
	else if (c == '$')
		ft_putchar_fd_c(LIGHT_BLUE, c, fd);
	else
		ft_putchar_fd(c, fd);
}

void		add_char(char c)
{
	t_shell	*shell;
	t_list	*new;

	shell = recover_shell();
	new = ft_lstnew(&c, sizeof(char));
	ft_lstadd_at(&shell->prompt->line, new, shell->prompt->i_pos);
	shell->prompt->i_pos++;
}

void		inser_char(char c)
{
	t_shell	*shell;
	t_list	*new;
	t_term	*term;

	shell = recover_shell();
	term = recover_term();
	new = ft_lstnew(&c, sizeof(char));
	ft_lstadd_at(&shell->prompt->line, new, shell->prompt->i_pos);
	shell->prompt->i_pos++;
	tputs(IMSTR, 0, ft_tputs);
	put_specific_char(c, term->tty);
	tputs(EISTR, 0, ft_tputs);
	if (shell->prompt->i_pos < ft_lstcount(shell->prompt->line))
	{
		print_eol();
	}
}
