/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/12 16:17:08 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H
# include <libft.h>
# include <builtins.h>
# include <shell.h>
# include <signal.h>
# include <env.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <stdio.h>
# include <sys/ioctl.h>

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

typedef struct	s_term
{
	t_termios	term;
	t_termios	old_term;
	t_winsize	wins;
	char		*term_name;
	int			tty;
}				t_term;

/*
** Term.c
*/
t_term			*recover_term(void);
int				init_term(void);
int				reset_term(void);
/*
** Term_utils.c
*/
int				ft_tputs(int c);
#endif
