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

	shell = recover_shell();
	prompt = shell->prompt;
	if (!ALT_X || prompt->flag_cut == 1)
		return (TRYING);
	prompt->flag_cut = 1;
	i = prompt->end_cpy - prompt->i_copy;
	clean_prompt();
	while (prompt->end_cpy-- > i)
	{
		ft_lstdel_at(&prompt->line, prompt->end_cpy, &free_char);
	}
	tputs(MESTR, 0, ft_tputs);
	ft_lstshow_x(prompt->line, 0);
	prompt->i_position = ft_lstcount(prompt->line);
	while (prompt->i_position > i)
		utils_move_left();
	return (READING);
}
