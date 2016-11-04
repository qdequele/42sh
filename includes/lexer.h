/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/21 15:59:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <libft.h>

# define M_WRITE_APPEND (O_WRONLY | O_NONBLOCK | O_CREAT | O_APPEND)
# define M_WRITE_TRUNC (O_WRONLY | O_NONBLOCK | O_CREAT | O_TRUNC)
# define M_READ_TRUNC (O_RDONLY | O_NONBLOCK | O_CREAT | O_TRUNC)
# define M_READ (O_RDONLY | O_NONBLOCK)

# define _PIPE_ (ft_strchr(cmd, '|'))
# define _HEREDOC_ (((p_heredoc = ft_strchr(cmd, '<')) && p_heredoc[1] == '<'))
# define _REDIRECT_ENTRY_ ((ft_strchr(cmd, '<')))
# define _REDIRECTION_ ((ft_strchr(cmd, '>') && ft_strchr(cmd, '&') == NULL))
# define _AGGREGATOR_FD_ (ft_strchr(cmd, '&'))

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
    int         *fd;
    int         mode;
    char        *type_of;
}               t_redirection;

typedef struct  s_exec
{
    t_type      type;
    char        *cmd;
    char        **opt;
}               t_exec;

/*
** utils/body.c
*/
char    *body_left(char *cmd, char c);
char    *body_right(char *cmd, char c);
/*
** utils/fork_close.c
*/
void    fork_close(int *f1);
/*
** exec.c
*/
int     exec_cmd(t_cmd *cmd);
t_cmd   *parse_cmd(char *cmd);
t_cmd   *build_exec(char *str);
/*
** heredoc.c
*/
t_cmd   *build_heredoc(char *cmd);
t_list  *heredoc_right(char *s1);
int     exec_heredoc(t_cmd *cmd);
void    put_heredoc_result(t_heredoc *p_cmd, int *p);
/*
** lexer.c
*/
t_cmd  *parse_cmd(char *cmd);
/*
** parse_redirection.c
*/
char    *parse_left(char *str);
char    *parse_right(char *str);
int     *parse_fd(char *pattern);
int     parse_mode(char *pattern);
char    *parse_type(char *pattern);
/*
** pipe.c
*/
t_cmd   *build_pipe(char *left, char *right);
t_cmd   *parse_pipe(char *complet_pipe);
int     exec_pipe(t_cmd *cmd);
/*
** redirect_entry.c
*/
t_cmd   *parse_redirect_entry(char *cmd);
/*
** redirection.c
*/
t_cmd   *build_redirection(char **body, int mode, int *fd, char *type_of);
t_cmd   *parse_redirection(char *redirection);
void    exec_redirection(t_cmd *cmd);

#endif