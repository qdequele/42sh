/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/09 13:59:57 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	env_parse_to_list(t_list **l_env, char **environ)
{
	int		i;
	t_env	*env;
	char	**array;

	i = 0;
	while (environ && environ[i])
	{
		env = (t_env *)malloc(sizeof(t_env));
		array = ft_strsplit(environ[i], '=');
		env->key = (array[0]) ? ft_strdup(array[0]) : ft_strdup("");
		if (ft_strcmp(env->key, "SHLVL") == 0)
		{
			env->value = ft_itoa(ft_atoi(array[1]) + 1);
		}
		else
		{
			env->value = (array[1]) ? ft_strdup(array[1]) : ft_strdup("");
		}
		ft_lstaddend(l_env, ft_lstnew(env, sizeof(t_env)));
		free(env);
		ft_free_aoc(array);
		i++;
	}
}

char	**env_parse_from_list(t_list *l_env)
{
	int		i;
	char	**environ;
	t_list	*elem;
	char	*value;
	char	*key;

	environ = (char **)malloc(sizeof(char *) * (ft_lstcount(l_env) + 1));
	i = 0;
	elem = l_env;
	while (elem)
	{
		value = (((t_env *)elem->content)->value) ?
			((t_env *)elem->content)->value : ft_strdup("");
		key = (((t_env *)elem->content)->key) ?
			((t_env *)elem->content)->key : ft_strdup("");
		environ[i] = ft_strfjoin(ft_strfjoin(key, "="), value);
		elem = elem->next;
		i++;
	}
	environ[i] = NULL;
	return (environ);
}
