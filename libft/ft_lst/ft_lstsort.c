/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:17:19 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/02 11:43:47 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_bubble_sort(t_list *node, int (*c)(t_list *node))
{
	int			swapped;
	t_list		*ptr1;
	t_list		*lptr;

	lptr = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = node;
		while (ptr1 && ptr1->next != lptr)
		{
			if (c(ptr1))
			{
				ft_lst_swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

void	ft_lst_swap(t_list *node1, t_list *node2)
{
	void	*temp;

	temp = node1->content;
	node1->content = node2->content;
	node2->content = temp;
}
