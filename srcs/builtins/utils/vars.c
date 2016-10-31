/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 15:54:53 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_list	*vars_recover(void)
{
	static t_list	*global_vars;
	if (global_vars == NULL)
	{
		global_vars = (t_list *)malloc(sizeof(t_list));
		global_vars = ft_lstnew(NULL, 0);
	}
	return (global_vars);
}

void	vars_init(void)
{
	t_list	*elem;

	elem = vars_recover();
	elem = (t_list *)malloc(sizeof(t_list));
	elem->content = NULL;
	elem->next = NULL;
}

void	vars_show(t_list *l_var)
{
	t_list	*elem;
	t_var	*var;

	elem = l_var;
	if (elem && elem->content)
	{
		while (elem && elem->content)
		{
			var = elem->content;
			if (var->key != NULL && ft_strlen(var->key) != 0 && var->value != NULL && ft_strlen(var->value) != 0)
			{
				ft_putstr(var->key);
				ft_putstr("=");
				ft_putstr(var->value);
				if (var->readonly == 1)
					ft_putstr(" - (readonly)");
				ft_putstr("\n");
			}
			
			elem = elem->next;
		}
	}
}

char	*vars_get(t_list *l_var, char *f_key)
{
	t_list	*elem;
	t_var	*var;

	elem = l_var;
	if (elem)
	{
		while (elem)
		{
			var = elem->content;
			if (var && var->key && var->value
				&& ft_strlen(var->key) > 0 && ft_strlen(var->value) > 0
				&& ft_strcmp(var->key, f_key) == 0)
				return (var->value);
			elem = elem->next;
		}
	}
	return ("");
}

void	vars_add_or_modify(t_list **l_vars, char *key, char *value)
{
	t_list	*elem;
	t_var	*var;

	elem = *l_vars;
	while (elem)
	{
		if (ft_strcmp(((t_var *)elem->content)->key, key) == 0)
		{
			if (((t_var *)elem->content)->readonly == 1)
				return ;
			free(((t_var *)elem->content)->value);
			((t_var *)elem->content)->value = value;
			return ;
		}
		elem = elem->next;
	}
	var = (t_var *)malloc(sizeof(t_var));
	var->key = key;
	var->value = value;
	var->readonly = 0;
	ft_lstaddend(l_vars, ft_lstnew(var, sizeof(t_var)));
}
