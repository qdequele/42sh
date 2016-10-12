/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:57:54 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 11:31:56 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nextlst;
	t_list	*list;

	list = *alst;
	if (!alst || !del)
		return ;
	while (list)
	{
		nextlst = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nextlst;
	}
	*alst = NULL;
}
