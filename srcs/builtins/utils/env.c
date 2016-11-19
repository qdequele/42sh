/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 18:54:55 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void			env_show(t_list *l_env)
{
	t_list		*elem;
	t_env		*env;

	elem = l_env;
	if (elem && elem->content)
	{
		while (elem)
		{
			env = elem->content;
			ft_putstr_fd(env->key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(env->value, 1);
			elem = elem->next;
		}
	}
}

char			*env_get(t_list *l_env, char *f_key)
{
	t_list		*elem;
	t_env		*env;

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

void			env_add_or_modify(t_list **l_env, char *key, char *value)
{
	t_list		*elem;
	t_env		*env;

	elem = *l_env;
	while (elem)
	{
		if (ft_strcmp(((t_env *)elem->content)->key, key) == 0)
		{
			free(((t_env *)elem->content)->value);
			((t_env *)elem->content)->value = ft_strdup(value);
			return ;
		}
		elem = elem->next;
	}
	env = (t_env *)malloc(sizeof(t_env));
	env->key = ft_strdup(key);
	env->value = ft_strdup(value);
	ft_lstaddend(l_env, ft_lstnew(env, sizeof(t_env)));
	free(env);
}

void			env_free_one(void *elem, size_t size)
{
	t_env		*l_elem;

	UNUSED(size);
	l_elem = elem;
	if (l_elem->key)
	{
		free(l_elem->key);
	}
	if (l_elem->value)
	{
		free(l_elem->value);
	}
	free(l_elem);
}

void			env_free(t_list **l_env)
{
	ft_lstdel(l_env, &env_free_one);
}
