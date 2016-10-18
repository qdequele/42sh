/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/18 17:26:17 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <libft.h>
# include <prompt.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>

# define UNUSED(x) (void)(x)

typedef enum	e_mode
{
	NORMAL,
	COPY,
	HISTORY,
	AUTOCOMPLETE
}				t_mode;

typedef struct	s_shell
{
	t_list		*history;
	int			history_position;
	int			last_exit_code;
	t_prompt	*prompt;
	t_mode		mode;
}				t_shell;

/*
**	Shell.c
*/
void		shell_core(t_list **env, char **cmds);
void		shell_exec_line(char *line);
void		shell_get_lines(void);
/*
**	Shell_init.c
*/
t_shell		*recover_shell(void);
void		init_shell(void);
/*
**	Shell_print.c
*/
void		print_shell();
void		print_shell_err(char *s);

#endif
