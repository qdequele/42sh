/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/28 12:10:34 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_paste(char *b)
{
	t_shell		*shell;
	t_prompt	*prompt;
	size_t		i;
	int			j;

	shell = recover_shell();
	prompt = shell->prompt;
	i = 0;
	if (!ALT_V || !prompt->str_cpy)
		return (TRYING);
	j = prompt->i_pos;
	clean_prompt();
	while (i < ft_strlen(prompt->str_cpy))
	{
		ft_lstadd_at(&prompt->line,
			ft_lstnew(&prompt->str_cpy[i], sizeof(char)), j + i);
		i++;
	}
	i = j;
	ft_lstshow_x(prompt->line, 0);
	prompt->i_pos = ft_lstcount(prompt->line);
	while ((size_t)prompt->i_pos > i)
		utils_move_left();
	return (READING);
}
