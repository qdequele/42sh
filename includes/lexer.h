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
# include <libft.h>

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
    t_type      *left;
    t_type      *right;
}               t_heredoc;

typedef struct  s_redirection 
{
    t_type      type;
    int         fd_left;
    int         fd_right;
    int         mode;
}               t_redirection;

typedef struct          s_exec
{
    t_type              type;
    char                *cmd;
    char                **opt;
}                       t_exec;

/*
** lexer.c
*/
/*
** pipe.c
*/
t_cmd   *build_pipe(char *left, char *right);
t_cmd   *parse_pipe(char *complet_pipe);
void    exec_pipe(t_cmd *cmd);
/*
** exec.c
*/
void    exec_cmd(t_cmd *cmd);
t_cmd  *parse_cmd(char *cmd);
t_cmd   *build_exec(char *str);
/*
** utils/body.c
*/
char    *body_left(char *cmd, char c);
char    *body_right(char *cmd, char c);

#endif