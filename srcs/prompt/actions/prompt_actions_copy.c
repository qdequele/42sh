/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status		action_copy(char *buf)
{
	t_shell		*shell;
	t_prompt	*prompt;

	shell = recover_shell();
	prompt = shell->prompt;
	if (!Alt_C)
		return (TRYING);
	else if (prompt->copy_mode != 1 && Alt_C)
		prompt->copy_mode  = 1;
	else 
	{
		tputs(MESTR, 0, ft_tputs);
		prompt->copy_mode = 0;
	}
	if (prompt->i_position != ft_lstcount(prompt->line) && prompt->copy_mode == 1)
	{
		tputs(MRSTR, 0, ft_tputs);
		prompt->str_cpy[prompt->i_copy] = (char)ft_lstget_at(prompt->line, prompt->i_position)->content;
		ft_putchar(prompt->str_cpy[prompt->i_position]);
		prompt->i_copy++;
	}
	return (READING);
}
