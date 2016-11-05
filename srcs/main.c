/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
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

char	*read_input(void)
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
		// ft_console("%d-%d-%d-%d-%d-%d-%d-%d\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
		if (buf[0] != 0)
		{
			if (!TAB)
				shell->autocomplete_position = 0;
			if ((copy_status = main_action_copy(buf)) == EXIT)
				status = prompt_find_function(buf);
			ft_bzero(buf, 8);
			if (status == FOUND)
				if (check_quote(list_to_string()) == 1)
					return (list_to_string());
		}
	}
	return (ft_strdup(""));
}

void	shell_start(void)
{
	t_shell	*shell;
	char	*line;

	shell = recover_shell();
	while (1)
	{
		init_shell();
		init_term();
		print_shell();
		shell->history_position = -1;
		shell->autocomplete_position = 0;
		line = read_input();
		if (line)
		{
			signal(SIGINT, SIG_IGN);
			reset_term();
			process_input(line);
			ft_lstadd(&shell->history,
				ft_lstnew(line, sizeof(char*) * ft_strlen(line)));
			free(line);
			ignore_major_signals();
		}

	}
	return ;
}

int			main(int argc, char **argv, char **environ)
{
	t_term	*term;
	t_shell	*shell;

	UNUSED(argv);
	g_env = NULL;
	g_vars = NULL;
	if (argc > 1)
	{
		ft_putendl_fd("21sh cannot have arguments", 2);
		return (0);
	}
	term = recover_term();
	shell = recover_shell();
	term->tty = open("/dev/tty", O_RDWR);
	shell->pgid = getpgrp();
	ft_console_log_clear();
	env_parse_to_list(&g_env, environ);
	ignore_major_signals();
	if (init_term() == -1)
	{
		ft_putendl_fd("21sh cannot be launch without termcaps", 2);
		reset_term();
		return (1);
	}
	shell_start();
	return (0);
}
