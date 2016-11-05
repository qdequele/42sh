/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 16:12:46 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void		process_input(char *input)
{
	t_list	*token_list;
	t_list	*job_list;

	token_list = input_to_token_list(input);
	update_job_status();
	if (check_lexer(token_list) == 0)
	{
		job_list = token_list_to_job_list(token_list);
		exec_job_list(job_list);
	}
}

void	shell_get_lines(void)
{
	t_shell	*shell;
	char	*line;

	shell = recover_shell();
	init_shell();
	while (1)
	{
		print_shell();
		shell->history_position = -1;
		shell->autocomplete_position = 0;
		line = prompt_create_line();
		process_input(line);
		ft_lstadd(&shell->history,
			ft_lstnew(line, sizeof(char*) * ft_strlen(line)));
		free(line);
	}
	return ;
}
