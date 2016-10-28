/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 12:10:48 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status 	action_free(char *buf)
{
	t_shell 	*shell;
	t_prompt 	*prompt;

	shell = recover_shell();
	prompt = shell->prompt;
	if (!ALT_B)
		return (TRYING);
	prompt->str_cpy = ft_strnew(1);
	prompt->i_copy = 0;
	return (READING);
}
