/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	inser_char(char c)
{
	t_shell	*shell;
	t_list	*new;
	t_term	*term;

	shell = recover_shell();
	term = recover_term();
	new = ft_lstnew(&c, sizeof(char));
	ft_lstadd_at(&shell->prompt->line, new, shell->prompt->i_position);
	shell->prompt->i_position++;
	shell->prompt->l_length++;
	tputs(IMSTR, 0, ft_tputs);
	ft_putchar_fd(c, term->tty);
	tputs(EISTR, 0, ft_tputs);
	if (shell->prompt->i_position < shell->prompt->l_length)
	{
		print_eol();
	}
}

t_status	action_insert_char(char *buf)
{
	if (buf[0])
		inser_char(buf[0]);
	if (buf[1])
		inser_char(buf[1]);
	if (buf[2])
		inser_char(buf[2]);
	return (READING);
}

t_status	action_delete_char(char *buf)
{
	t_shell	*shell;

	if (!BACK_SPACE )
		return (TRYING);
	shell = recover_shell();
	if(shell->prompt->i_position <= shell->prompt->l_length
		&& shell->prompt->i_position > 0)
	{
		tputs(LESTR, 1, ft_tputs);// move left
		tputs(DMSTR, 1, ft_tputs);// enter in delete mode
		tputs(DCSTR, 1, ft_tputs);// delete char
		tputs(EDSTR, 1, ft_tputs);// exit delete mode
		shell->prompt->i_position--;
		shell->prompt->l_length--;
		ft_lstdel_at(&shell->prompt->line, shell->prompt->i_position, free_char);
	}
	return (READING);
}

t_status	action_delete_next_char(char *buf)
{
	t_shell	*shell;

	if (!DELETE )
		return (TRYING);
	shell = recover_shell();
	if(shell->prompt->i_position < shell->prompt->l_length
		&& shell->prompt->i_position >= 0)
	{
		tputs(DMSTR, 1, ft_tputs);// enter in delete mode
		tputs(DCSTR, 1, ft_tputs);// delete char
		tputs(EDSTR, 1, ft_tputs);// exit delete mode
		shell->prompt->l_length--;
		ft_lstdel_at(&shell->prompt->line, shell->prompt->i_position, free_char);
	}
	return (READING);
}