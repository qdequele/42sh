/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 12:37:24 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			vars_show(t_list *l_var)
{
	t_list	*elem;
	t_var	*var;

	elem = l_var;
	if (elem && elem->content)
	{
		while (elem && elem->content)
		{
			var = elem->content;
			if (var->key != NULL && ft_strlen(var->key) != 0
					&& var->value != NULL)
			{
				ft_putstr_fd(var->key, 2);
				ft_putstr_fd("=", 2);
				ft_putstr_fd(var->value, 2);
				if (var->readonly == 1)
					ft_putstr_fd(" - (readonly)", 2);
				ft_putstr_fd("\n", 2);
			}
			elem = elem->next;
		}
	}
	return (0);
}

char		*vars_get(t_list *l_var, char *f_key)
{
	t_list	*elem;
	t_var	*var;

	elem = l_var;
	if (elem)
	{
		while (elem)
		{
			var = elem->content;
			if (var && var->key && ft_strlen(var->key) > 0
				&& ft_strcmp(var->key, f_key) == 0)
			{
				if (var->value && ft_strlen(var->value) > 0)
					return (var->value);
				else
					return ("");
			}
			elem = elem->next;
		}
	}
	return (NULL);
}

void		vars_add_or_modify(t_list **l_vars, char *key, char *value)
{
	t_list	*elem;
	t_var	*var;

	elem = *l_vars;
	while (elem && elem->content)
	{
		if (ft_strcmp(((t_var *)elem->content)->key, key) == 0)
		{
			if (((t_var *)elem->content)->readonly == 1)
				return ;
			free(((t_var *)elem->content)->value);
			((t_var *)elem->content)->value = ft_strdup(value);
			return ;
		}
		elem = elem->next;
	}
	var = (t_var *)malloc(sizeof(t_var));
	var->key = ft_strdup(key);
	var->value = ft_strdup(value);
	var->readonly = 0;
	ft_lstaddend(l_vars, ft_lstnew(var, sizeof(t_var)));
	free(var);
}

int			vars_change_readonly(t_list **l_vars, char *key, int rdo)
{
	t_list	*elem;

	elem = *l_vars;
	while (elem && elem->content)
	{
		if (ft_strcmp(((t_var *)elem->content)->key, key) == 0)
		{
			((t_var *)elem->content)->readonly = rdo;
			return (0);
		}
		elem = elem->next;
	}
	return (1);
}
