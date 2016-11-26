/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/20 19:23:45 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <ft_sh.h>
# define UNUSED(x) (void)(x)

# define TEST_MODE 1

typedef enum			e_mode
{
	NORMAL,
	COPY,
	QUOTE
}						t_mode;

typedef struct			s_shell
{
	t_list				*history;
	int					history_position;
	int					history_index;
	t_list				*posibilities;
	int					autocomplete_position;
	int					last_exit_code;
	t_prompt			*prompt;
	t_mode				mode;
	int					signals_disabled;
	pid_t				pgid;
	t_list				*jobs;
}						t_shell;

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

typedef struct			s_term
{
	t_termios			term;
	t_termios			old_term;
	t_winsize			wins;
	char				*term_name;
	int					tty;
}						t_term;

int						shell_start(void);
void					process_input(char *input);
t_shell					*recover_shell(void);
void					init_shell(void);
void					free_shell(void);
void					print_shell();
void					print_err(char *str1, char *str2);
void					print_tty(char *str);
void					printendl_tty(char *str);
void					ignore_major_signals(void);
void					reset_major_signals(void);
void					signal_reprompt(int i);
void					signal_resize_screen(int i);
t_term					*recover_term(void);
int						init_term(int save);
int						reset_term(void);
int						ft_tputs(int c);
void					reset_autocomplete_possibilities(void);
void					free_input(void);
void					add_history(char *line);

#endif
