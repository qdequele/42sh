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

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	if (*alst == NULL && new)
		*alst = new;
	else
	{
		while (list->next)
		{
			list = list->next;
		}
		list->next = new;
	}
}
