/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void			inser_char(char c)
{
	t_shell	*shell;
	t_list	*new;
	t_term	*term;

	shell = recover_shell();
	term = recover_term();
	new = ft_lstnew(&c, sizeof(char));
	ft_lstadd_at(&shell->prompt->line, new, shell->prompt->i_position);
	shell->prompt->i_position++;
	tputs(IMSTR, 0, ft_tputs);
	ft_putchar_fd(c, term->tty);
	tputs(EISTR, 0, ft_tputs);
	if (shell->prompt->i_position < ft_lstcount(shell->prompt->line))
	{
		print_eol();
	}
}

t_status		action_insert_char(char *buf)
{
	if (TAB)
	{
		inser_char(' ');
		inser_char(' ');
		inser_char(' ');
		inser_char(' ');
	}
	else if (buf[0])
		inser_char(buf[0]);
	else if (buf[1])
		inser_char(buf[1]);
	else
		inser_char(buf[2]);
	return (READING);
}

t_status		action_delete_char(char *buf)
{
	if (!BACK_SPACE)
		return (TRYING);
	erase_one_char();
	return (READING);
}

t_status		action_delete_next_char(char *buf)
{
	if (!DELETE)
		return (TRYING);
	delete_one_char();
	return (READING);
}
