/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 15:53:49 by qdequele         ###   ########.fr       */
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

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

t_list				*g_env;

typedef struct 		s_var
{
	char 			*key;
	char			*value;
	int 			readonly;
}					t_var;

t_list 				*g_vars;

/*
**	builtins
*/
int					builtins_cd(t_list **env, char **cmds);
int					builtins_env(t_list **env, char **cmds);
int					builtins_exit(t_list **env, char **cmds);
int					builtins_history(t_list **env, char **cmds);
int					builtins_setenv(t_list **env, char **cmds);
int					builtins_unsetenv(t_list **env, char **cmds);
int					builtins_set(t_list **env, char **cmds);
int					builtins_unset(t_list **env, char **cmds);
int					builtins_export(t_list **env, char **cmds);
void				bultins_one_history(char *str);
int					builtins_echo(t_list **env, char **cmds);
/*
** read.c
*/
int					builtins_read(t_list **env, char **cmds);
int					count_words(char *s, char c);
void				create_last_var(char *var_name, char **var_value);
void				create_var(char *var_name, char *var_value);
/*
**	builtins utils
*/
t_builtin			*builtins_init(void);
int					builtins_find(char *cmd);
int					builtins_exec(t_list **env, char **cmds);
void				remove_key(t_list **head, char *key);
/*
**	utils - env_parser.c
*/
void				env_parse_to_list(t_list **l_env, char **environ);
char				**env_parse_from_list(t_list *l_env);
/*
**	utils - env_utils.c
*/
void				env_show(t_list *l_env);
char				*env_get(t_list *l_env, char *f_key);
void				env_add_or_modify(t_list **l_env, char *key, char *value);
/*
**	utils - vars_utils.c
*/
void				vars_init(void);
t_list				*vars_recover(void);
void				vars_show(t_list *l_var);
char				*vars_get(t_list *l_var, char *f_key);
void				vars_add_or_modify(t_list **l_vars, char *key, char *value);

#endif
