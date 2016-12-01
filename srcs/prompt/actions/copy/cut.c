/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/28 12:10:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_cut(char *b)
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
	prompt->i_pos = ft_lstcount(prompt->line);
	while (prompt->i_pos > i)
		utils_move_left();
	return (READING);
}
