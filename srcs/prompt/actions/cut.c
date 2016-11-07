/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/28 12:10:47 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_cut(char *buf)
{
	t_shell		*shell;
	t_prompt	*prompt;
	t_list		*cur;
	int			i;

	shell = recover_shell();
	prompt = shell->prompt;
	if (!ALT_X)
		return (TRYING);
	i = prompt->i_position - prompt->i_copy;
	cur = prompt->line;
	clean_prompt();
	while (prompt->i_position-- > i)
	{
		cur = prompt->line;
		ft_lstdel_at(&cur, prompt->i_position, &free_char);
	}
	cur = prompt->line;
	tputs(MESTR, 0, ft_tputs);
	ft_lstshow_x(cur, 0);
	prompt->i_position = ft_lstcount(prompt->line);
	while (prompt->i_position > i)
		utils_move_left();
	return (READING);
}
