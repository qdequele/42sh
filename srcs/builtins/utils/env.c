/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 11:48:56 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	env_show(t_list *l_env)
{
	t_list	*elem;
	t_env	*env;

	elem = l_env;
	if (elem && elem->content)
	{
		while (elem)
		{
			env = elem->content;
			ft_putstr(env->key);
			ft_putstr("=");
			ft_putendl(env->value);
			elem = elem->next;
		}
	}
}

char	*env_get(t_list *l_env, char *f_key)
{
	t_list	*elem;
	t_env	*env;

	elem = l_env;
	if (elem)
	{
		while (elem)
		{
			env = elem->content;
			if (env && env->key && env->value
				&& ft_strlen(env->key) > 0 && ft_strlen(env->value) > 0
				&& ft_strcmp(env->key, f_key) == 0)
				return (env->value);
			elem = elem->next;
		}
	}
	return ("");
}

void	env_add_or_modify(t_list **l_env, char *key, char *value)
{
	t_list	*elem;
	t_env	*env;

	elem = *l_env;
	while (elem)
	{
		if (ft_strcmp(((t_env *)elem->content)->key, key) == 0)
		{
			free(((t_env *)elem->content)->value);
			((t_env *)elem->content)->value = value;
			return ;
		}
		elem = elem->next;
	}
	env = (t_env *)malloc(sizeof(t_env));
	env->key = key;
	env->value = value;
	ft_lstaddend(l_env, ft_lstnew(env, sizeof(t_env)));
}
