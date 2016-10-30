/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/30 17:38:48 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*prompt_create_line(void)
{
	t_prompt	*prompt;
	char		buf[9];
	t_status	status;
	t_status 	copy_status;
	t_shell		*shell;

	shell = recover_shell();
	prompt = init_prompt();
	shell->prompt = prompt;
	ft_bzero(buf, 9);
	while (read(0, buf, 9))
	{
		if (!TAB)
			shell->autocomplete_position = 0;
		if ((copy_status = main_action_copy(buf)) == EXIT)
			status = prompt_find_function(buf);
		ft_bzero(buf, 9);
		if (status == FOUND)
			if (check_quote(list_to_string()) == 1)
				return (list_to_string());
	}
	return (NULL);
}
