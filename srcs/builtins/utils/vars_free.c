/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 22:06:05 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void		vars_free_one(void *elem, size_t size)
{
	t_var	*l_elem;

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

void		vars_free(t_list **l_vars)
{
	ft_lstdel(l_vars, &vars_free_one);
}
