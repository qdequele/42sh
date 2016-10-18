/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/18 17:30:19 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status  action_copy_quit(char *buf)
{
	(void)buf;
	return (EXIT);
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
	if (!ALT_C && !ALT_V && !ALT_B)
		return (EXIT);
	status_copy = TRYING;
	while ((*actions_copy && status_copy == TRYING) || status_copy != EXIT)
	{
		status_copy = (*actions_copy)(buf);
		actions_copy++;
	}
	return (READING);
}
