/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:57:54 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 19:19:56 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel_at(t_list **list, int at, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*prev;
	int		count;

	if (!list || !(*list))
		return ;
	tmp = *list;
	prev = NULL;
	count = 0;
	while (count != at && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		count++;
	}
	if (count == at)
	{
		if (prev)
			prev->next = tmp->next;
		else
			*list = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
}
