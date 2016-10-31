/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:14:23 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 17:15:04 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	__DEBUG__
	if ((*alst == NULL || (*alst)->content == NULL )&& new)
	{
		__DEBUG__
		*alst = new;
	}
	else
	{
		__DEBUG__
		while (list->next)
		{
			__DEBUG__
			list = list->next;
		}
		__DEBUG__
		list->next = new;
		__DEBUG__
	}
}
