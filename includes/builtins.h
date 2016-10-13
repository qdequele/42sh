/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:32:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <libft.h>

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
int					builtins_setenv(t_list **env, char **cmds);
int					builtins_unsetenv(t_list **env, char **cmds);
int 				builtins_history(t_list **env, char **cmds);
void				bultins_one_history(char *str);
/*
**	builtins help
*/
int					builtins_find(char *cmd);
int					builtins_exec(t_list **env, char **cmds);

#endif