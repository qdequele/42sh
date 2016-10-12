/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:14:23 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 11:39:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_lstcount(t_list *lst)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = lst;
	if (elem)
	{
		while (elem)
		{
			i++;
			elem = elem->next;
		}
	}
	return (i);
}
