/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:51:24 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <libft.h>\

# define M_WRITE_APPEND (O_WRONLY | O_NONBLOCK | O_CREAT | O_APPEND)
# define M_WRITE_TRUNC (O_WRONLY | O_NONBLOCK | O_CREAT | O_TRUNC)

typedef enum    e_type
{
    ERROR,
    REDIRECTION,
    PIPE,
    HEREDOC,
    EXEC
}               t_type;

typedef struct  s_cmd 
{
    t_type      type;
}               t_cmd;

typedef struct   s_pipe 
{
    t_type      type;
    t_cmd       *left;
    t_cmd       *right;
}               t_pipe;

typedef struct   s_error 
{
    t_type      type;
    char        *msg;
}               t_error;

typedef struct   s_heredoc 
{
    t_type      type;
    t_cmd       *left;
    t_list      *right;
}               t_heredoc;

typedef struct  s_redirection 
{
    t_type      type;
    t_cmd       *left;
    char        *right;
    int         fd_left;
    int         fd_right;
    int         mode;
}               t_redirection;

typedef struct  s_exec
{
    t_type      type;
    char        *cmd;
    char        **opt;
}               t_exec;

/*
** lexer.c
*/
t_cmd  *parse_cmd(char *cmd);
/*
** utils/fork_close.c
*/
void    fork_close(int *f1);
/*
** heredoc.c
*/
t_cmd   *build_heredoc(char *left, t_list *list);
t_cmd   *parse_heredoc(char *complet_pipe);
t_list  *heredoc_right(char *s1);
void    exec_heredoc(t_cmd *cmd);
void    put_heredoc_result(t_heredoc *p_cmd, int *p);
/*
** pipe.c
*/
t_cmd   *build_pipe(char *left, char *right);
t_cmd   *parse_pipe(char *complet_pipe);
void    exec_pipe(t_cmd *cmd);
/*
** redirection.c
*/
t_cmd   *build_redirection(char *left, char *right, int mode, int fd_left, int fd_right);
void    exec_redirection(t_cmd *cmd);
t_cmd   *parse_redirection(char *redirection);
char    *parse_left(char *str);
char    *parse_right(char *str);
int     *parse_fd(char *pattern);
int     parse_mode(char *pattern);
/*
** exec.c
*/
void    exec_cmd(t_cmd *cmd);
t_cmd   *build_exec(char *str);
/*
** utils/body.c
*/
char    *body_left(char *cmd, char c);
char    *body_right(char *cmd, char c);

#endif