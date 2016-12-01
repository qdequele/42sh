/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/28 12:10:48 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void		free_copy(void)
{
	t_shell		*shell;
	t_prompt	*prompt;

	shell = recover_shell();
	prompt = shell->prompt;
	free(prompt->str_cpy);
	prompt->str_cpy = NULL;
	prompt->i_copy = 0;
	prompt->flag_cut = 0;
}

t_status	action_free(char *b)
{
	if (!ALT_B)
		return (TRYING);
	free_copy();
	return (READING);
}
