/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 12:11:03 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status		action_copy_quit(char *buf)
{
	(void)buf;
	return (EXIT);
}

t_status		action_copy(char *buf)
{
	t_shell		*shell;
	t_prompt	*prompt;
	char		*tmp;

	shell = recover_shell();
	prompt = shell->prompt;
	if (!ALT_C || prompt->flag_cut == 1)
		return (TRYING);
	if (!prompt->str_cpy || prompt->str_cpy[0] == '\0')
		prompt->str_cpy = (char*)malloc(sizeof(char*) + 1);
	if (prompt->i_position != ft_lstcount(prompt->line))
	{
		tmp = ft_strsub(((char*)ft_lstget_at(
			prompt->line, prompt->i_position)->content), 0, 1);
		prompt->str_cpy = ft_strfjoin(prompt->str_cpy, tmp);
		tputs(MRSTR, 0, ft_tputs);
		ft_putchar_fd(prompt->str_cpy[prompt->i_copy], recover_term()->tty);
		tputs(MESTR, 0, ft_tputs);
		prompt->i_position++;
		prompt->i_copy++;
		free(tmp);
	}
	prompt->end_cpy = prompt->i_position;
	return (TRYING);
}

t_status		main_action_copy(char *buf)
{
	t_status	(**actions_copy)(char *);
	t_status	status_copy;

	actions_copy = get_actions_copy();
	if (!ALT_C && !ALT_V && !ALT_B && !ALT_X)
		return (EXIT);
	status_copy = TRYING;
	while ((*actions_copy && status_copy == TRYING) || status_copy != EXIT)
	{
		status_copy = (*actions_copy)(buf);
		actions_copy++;
	}
	return (READING);
}
