/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:32:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <libft.h>

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct 		s_local
{
	char 			*key;
	char			*value;
}					t_local;

t_list 				*g_local;
t_list				*g_env;

/*
**	env - env_parser.c
*/
void				env_parse_to_list(t_list **l_env, char **environ);
char				**env_parse_from_list(t_list *l_env);
/*
**	env - env_utils.c
*/
void				env_show(t_list *l_env);
char				*env_get(t_list *l_env, char *f_key);
void				env_add_or_modify(t_list **l_env, char *key, char *value);
void				env_remove(t_list *l_env, char *key);

#endif