/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_paste.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/18 16:12:09 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_paste(char *buf)
{
	t_shell		*shell;
	t_prompt	*prompt;
	size_t		i;
	int 		j;

	shell = recover_shell();
	prompt = shell->prompt;
	j = 0;
	i = 0;
	if (!ALT_V)
		return (TRYING);
	while (i < ft_strlen(prompt->str_cpy))
	{
		ft_lstadd_at(&prompt->line,
			ft_lstnew(&prompt->str_cpy[i], sizeof(char*)), prompt->i_position + i - 1);
		i++;
	}
	i = prompt->i_position;
	clean_prompt();
	while ((size_t)j < i)
		utils_move_right();
	ft_lstshow_x(prompt->line, 0);
	prompt->i_position = i;
	return (READING);
}
