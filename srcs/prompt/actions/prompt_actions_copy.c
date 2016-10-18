/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static t_status  action_copy_quit(char *buf)
{
	(void)buf;
	return (EXIT);
}
static void		*get_actions_copy(void)
{
	static t_status (*f[])(char *) = {
		action_move_right,
		action_move_left,
		action_exec_cmd,
		action_paste,
		action_copy,
		action_cut,
		action_copy_quit
	};
	
	return ((void *)f);
}

t_status		action_copy(char *buf)
{
	t_shell		*shell;
	t_term 		*term;
	t_prompt	*prompt;

	shell = recover_shell();
	term = recover_term();
	prompt = shell->prompt;
	if (!ALT_C)
		return (TRYING);
	// if (prompt->i_copy == 0)
	// 	tputs(SCSTR, 0, ft_tputs);
	if (prompt->i_position != ft_lstcount(prompt->line))
	{
		prompt->str_cpy[prompt->i_copy] = *(char*)(ft_lstget_at(prompt->line, prompt->i_position)->content);
		tputs(MRSTR, 0, ft_tputs);
		ft_putchar_fd(prompt->str_cpy[prompt->i_copy], term->tty);
		tputs(MESTR, 0, ft_tputs);
		prompt->i_position++;
		prompt->i_copy++;

	}
	return (TRYING);
}


t_status	main_action_copy(char *buf)
{
	t_status	(**actions_copy)(char *);
	t_status	status_copy;

	actions_copy = get_actions_copy();
	if (!ALT_C && !ALT_V)
		return (EXIT);
	status_copy = TRYING;
	while ((*actions_copy && status_copy == TRYING) || status_copy != EXIT)
	{
		status_copy = (*actions_copy)(buf);
		actions_copy++;
	}
	return (READING);
}
