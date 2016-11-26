/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 22:56:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <ft_sh.h>

# define READ_OPT_R (ft_strcmp(cmds[1], "-r") == 0)
# define PATH_MAX 4096

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

typedef struct		s_var
{
	char			*key;
	char			*value;
	int				readonly;
}					t_var;

typedef struct		s_options
{
	char			options[256];
	int				start;
	int				error;
	int				error_char;
	int				options_counter;
}					t_options;

t_list				*g_env;
t_list				*g_l_vars;
t_list				*g_g_vars;
t_list				*g_export;

int					builtins_cd(t_list **env, char **cmds);
int					builtins_env(t_list **env, char **cmds);
int					builtins_exit(t_list **env, char **cmds);
int					builtins_history(t_list **env, char **cmds);
int					builtins_setenv(t_list **env, char **cmds);
int					builtins_unsetenv(t_list **env, char **cmds);
int					builtins_set(t_list **env, char **cmds);
int					builtins_unset(t_list **env, char **cmds);
int					builtins_export(t_list **env, char **cmds);
int					builtins_help(t_list **env, char **cmds);
char				*bultins_one_history(char *str);
void				history_free(t_list **l_history);
int					builtins_echo(t_list **env, char **cmds);
int					builtins_bg(t_list **env, char **cmds);
int					builtins_fg(t_list **env, char **cmds);
int					builtins_jobs(t_list **env, char **cmds);
void				free_jobs(t_list **jobs);
void				free_one_job(void *elem, size_t size);
int					builtins_read(t_list **env, char **cmds);
int					count_words(char *s, char c);
char				*check_value(char opt, char *var_value);
t_builtin			*builtins_init(void);
int					builtins_find(char *cmd);
int					builtins_exec(t_list **env, char **cmds);
int					remove_key(t_list **head, char *key,
						void (*del)(void *, size_t));
void				env_parse_to_list(t_list **l_env, char **environ);
char				**env_parse_from_list(t_list *l_env);
void				env_show(t_list *l_env);
char				*env_get(t_list *l_env, char *f_key);
void				env_add_or_modify(t_list **l_env, char *key, char *value);
void				env_free_one(void *elem, size_t size);
void				env_free(t_list **l_env);
int					shell_core(t_list **env, char **cmds);
void				create_last_var(char *var_name, char **var_value, char opt);
void				vars_init(void);
int					vars_show(t_list *l_var);
void				vars_show_global(t_list *l_var);
char				*vars_get(t_list *l_var, char *f_key);
void				vars_add_or_modify(t_list **l_vars, char *key, char *value);
int					vars_change_readonly(t_list **l_vars, char *key, int rdo);
void				vars_free_one(void *elem, size_t size);
void				vars_free(t_list **l_vars);
int					builtins_readonly(t_list **env, char **cmds);
int					builtins_unreadonly(t_list **env, char **cmds);
int					builtins_set_equal(t_list **env, char **cmds);
void				print_error_history(int i, char *cmds);
int					cd_error(int type, char *path);
char				*cd_assert_home(char *path);
char				*cd_assert_multiple_args(char **cmds, t_options *options);
void				cd_update_path(char *old_path, char *path);
int					cd_change_directory(char *curpath, int is_physical);
t_options			t_options_parser(char **cmds, char *m_options);

#endif
