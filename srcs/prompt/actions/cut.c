/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 12:10:47 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_cut(char *buf)
{
	t_shell		*shell;
	t_prompt	*prompt;
	int			i;
	int			position;

	shell = recover_shell();
	prompt = shell->prompt;
	if (!ALT_X || prompt->flag_cut == 1)
		return (TRYING);
	prompt->flag_cut = 1;
	i = prompt->i_position - prompt->i_copy;
	position = prompt->i_position;
	while (prompt->i_position-- > i)
	{
		ft_lstdel_at(&prompt->line, prompt->i_position, &free_char);
	}
	tputs(MESTR, 0, ft_tputs);
	prompt->i_position = position;
	clean_prompt();
	ft_lstshow_x(prompt->line, 0);
	prompt->i_position = ft_lstcount(prompt->line);
	while (prompt->i_position > i)
		utils_move_left();
	return (READING);
}