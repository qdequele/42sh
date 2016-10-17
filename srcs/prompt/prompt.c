/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/17 14:50:59 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*prompt_create_line(void)
{
	t_prompt	*prompt;
	char		buf[7];
	t_status	status;
	t_shell		*shell;

	shell = recover_shell();
	prompt = init_prompt();
	shell->prompt = prompt;
	ft_bzero(buf, 7);
	while (read(0, buf, 7))
	{
		//printf("%i - %i - %i - %i - %i - %i - %i|\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
		status = prompt_find_function(buf);
		ft_bzero(buf, 7);
		if (status == FOUND)
		{
			printf("--------------------------\n");
			ft_lstshow_x(shell->prompt->line, 0);
			printf("--------------------------\n");
			return (list_to_string());
		}
	}
	return (NULL);
}