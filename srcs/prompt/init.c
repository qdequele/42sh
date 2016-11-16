/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 19:17:05 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_prompt	*init_prompt(void)
{
	t_prompt		*prompt;

	prompt = (t_prompt*)malloc(sizeof(t_prompt));
	prompt->line = NULL;
	prompt->i_pos = 0;
	prompt->p_pos = 0;
	prompt->p_length = 0;
	prompt->i_copy = 0;
	prompt->flag_cut = 0;
	prompt->end_cpy = 0;
	prompt->str_cpy = NULL;
	prompt->cut_len = 0;
	prompt->quote_type = 0;
	prompt->quote_number = 0;
	return (prompt);
}

void		add_history(char *line)
{
	t_shell	*shell;

	shell = recover_shell();
	if (line[0] == '!' || (line[0] == ' ' && ft_strlen(line) == 1) || ft_strlen(line) == 0)
		return ;
	ft_lstadd_at(&shell->history,
		ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1),
		shell->history_index);
	shell->history_index++;
}
