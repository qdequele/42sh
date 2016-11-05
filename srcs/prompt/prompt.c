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
	char		buf[8];
	t_status	status;
	t_status 	copy_status;
	t_shell		*shell;

	
	shell = recover_shell();
	prompt = init_prompt();
	
	shell->prompt = prompt;
	ft_bzero(buf, 8);
	
	while (read(0, buf, 8))
	{
		// perror("read : ");
		// ft_console("%d-%d-%d-%d-%d-%d-%d-%d\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
		if (buf[0] != 0)
		{
			
			if (!TAB)
			{
				
				shell->autocomplete_position = 0;
			}
			if ((copy_status = main_action_copy(buf)) == EXIT)
			{
				
				status = prompt_find_function(buf);
			}
			ft_bzero(buf, 8);
			if (status == FOUND)
			{
				
				if (check_quote(list_to_string()) == 1)
				{
					
					return (list_to_string());
				}
			}
		}
		
	}
	return (ft_strdup(""));
}
