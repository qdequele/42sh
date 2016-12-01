/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/06 18:52:25 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char			*read_normal_input(void)
{
	t_prompt	*prompt;
	char		b[4];
	t_status	status;
	t_status	copy_status;
	t_shell		*shell;

	shell = recover_shell();
	prompt = init_prompt();
	shell->prompt = prompt;
	prompt->p_length = get_normal_prompt_length();
	ft_bzero(b, 4);
	while (read(0, b, 4))
	{
		if (!TAB)
			reset_autocomplete_possibilities();
		if ((copy_status = main_action_copy(b)) == EXIT)
			status = prompt_find_function(b);
		ft_bzero(b, 4);
		if (status == FOUND && check_quote(list_to_string()) == 1)
			return (list_to_string());
	}
	return (ft_strdup(""));
}
