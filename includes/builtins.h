/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 15:02:01 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <libft.h>


#define EXPORTS (ft_strcmp(cmds[0], "export") == 0)
typedef int	(*t_func)(t_list **env, char **cmds);

typedef struct stat	t_stat;

typedef struct		s_builtin
{
	char			*name;
	t_func			f;
}					t_builtin;

/*
**	builtins
*/
int					builtins_cd(t_list **env, char **cmds);
int					builtins_env(t_list **env, char **cmds);
int					builtins_exit(t_list **env, char **cmds);
int					builtins_history(t_list **env, char **cmds);
int					builtins_setenv(t_list **env, char **cmds);
int					builtins_unsetenv(t_list **env, char **cmds);
void				bultins_one_history(char *str);
int					builtins_echo(t_list **env, char **cmds);
/*
** read.c
*/
int 				builtins_read(t_list **env, char **cmds);
int					count_words(char *s, char c);
void				create_last_var(char *var_name, char **var_value);
void				create_var(char *var_name, char *var_value);
/*
**	builtins help
*/
t_builtin			*builtins_init(void);
int					builtins_find(char *cmd);
int					builtins_exec(t_list **env, char **cmds);

#endif