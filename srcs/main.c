/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 19:17:26 by bjamin           ###   ########.fr       */
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
		free_jobs(&job_list);
	}
}

char			*read_input(void)
{
	t_prompt	*prompt;
	char		buf[8];
	t_status	status;
	t_status	copy_status;
	t_shell		*shell;

	shell = recover_shell();
	prompt = init_prompt();
	shell->prompt = prompt;
	ft_bzero(buf, 8);
	while (read(0, buf, 8))
	{
		if (!TAB)
			reset_autocomplete_possibilities();
		if ((copy_status = main_action_copy(buf)) == EXIT)
			status = prompt_find_function(buf);
		ft_bzero(buf, 8);
		if (status == FOUND && check_quote(list_to_string()) == 1)
			return (list_to_string());
	}
	return (ft_strdup(""));
}

void			shell_start(void)
{
	t_shell		*shell;
	char		*line;

	shell = recover_shell();
	init_shell();
	while (1)
	{
		init_term();
		print_shell();
		shell->history_position = -1;
		reset_autocomplete_possibilities();
		line = read_input();
		free_input();
		if (line)
		{
			signal(SIGINT, SIG_IGN);
			reset_term();
			process_input(line);
			add_history(line);
			ignore_major_signals();
		}
		free(line);
		free_input();
		free(shell->prompt);
	}
}

int				main(int argc, char **argv, char **environ)
{
	t_term	*term;
	t_shell	*shell;

	UNUSED(argv);
	g_env = NULL;
	g_vars = NULL;
	if (argc > 1)
	{
		ft_putendl_fd("42sh cannot have arguments", 2);
		return (0);
	}
	term = recover_term();
	shell = recover_shell();
	term->tty = open("/dev/tty", O_RDWR);
	shell->pgid = getpgrp();
	env_parse_to_list(&g_env, environ);
	ignore_major_signals();
	if (init_term() == -1)
	{
		ft_putendl_fd("42sh cannot be launch without termcaps", 2);
		reset_term();
		return (1);
	}
	shell_start();
	return (0);
}
