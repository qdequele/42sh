/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/21 22:25:06 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void			process_input(char *input)
{
	t_list	*token_list;
	t_list	*job_list;

	if (input[0] == '!')
		input = bultins_one_history(input);
	token_list = input_to_token_list(input);
	update_job_status();
	if (check_lexer(token_list) == 0)
	{
		job_list = token_list_to_job_list(token_list);
		exec_job_list(job_list);
		free_jobs(&job_list);
	}
}

static void		load_shell(void)
{
	init_shell();
	load_history();
	load_vars();
}

int				shell_start(void)
{
	char		*line;

	while (recover_shell()->last_exit_code == -1)
	{
		init_term(0);
		print_shell();
		recover_shell()->history_position = -1;
		line = read_normal_input();
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
		reset_autocomplete_possibilities();
		free(recover_shell()->prompt);
	}
	free_shell();
	return (recover_shell()->last_exit_code);
}

int				shell_file(char **argv)
{
	char		*line;
	int			fd;
	int			res;

	fd = (!isatty(0)) ? 0 : open(argv[1], O_RDWR);
	while (fd >= 0 && ft_get_next_line(fd, &line) &&
		recover_shell()->last_exit_code == -1)
	{
		if (line)
		{
			signal(SIGINT, SIG_IGN);
			process_input(line);
			ignore_major_signals();
		}
		free(line);
		free(recover_shell()->prompt);
	}
	if (recover_shell()->last_exit_code == -1)
		res = ft_atoi(vars_get(g_l_vars, "?"));
	else
		res = recover_shell()->last_exit_code;
	free_shell();
	return (res);
}

int				main(int argc, char **argv, char **environ)
{
	t_term	*term;
	t_shell	*shell;

	UNUSED(argv);
	g_env = NULL;
	g_l_vars = NULL;
	term = recover_term();
	shell = recover_shell();
	term->tty = open("/dev/tty", O_RDWR);
	shell->pgid = getpgrp();
	ignore_major_signals();
	if (init_term(1) == -1)
	{
		ft_putendl_fd("42sh cannot be launch without termcaps", 2);
		reset_term();
		return (1);
	}
	env_parse_to_list(&g_env, environ);
	env_parse_to_list(&g_export, environ);
	load_shell();
	UNUSED(argc);
	if (argc > 1 || !isatty(0))
		return (shell_file(argv));
	return (shell_start());
}
