/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_cut.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_cut(char *buf)
{
	t_shell		*shell;
	t_prompt	*prompt;
	t_list		*cur;
	int			i;
	int			j;

	shell = recover_shell();
	prompt = shell->prompt;
	if (!ALT_X)
		return (TRYING);
	j = prompt->i_position;
	i = prompt->i_position - prompt->i_copy;
	cur = prompt->line;
	clean_prompt();
	while (j-- > i)
	{
		cur = prompt->line;
		ft_lstdel_at(&cur, j, &free_char);
	}
	cur = prompt->line;
	tputs(MESTR, 0, ft_tputs);
	ft_lstshow_x(cur, 0);
	tputs(RCSTR , 0, ft_tputs);
	prompt->i_position = j + 1;
	return (READING);
}