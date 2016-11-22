/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:57:54 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/29 16:59:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstremdup(t_list **list, int (*comp)(void *, void *),
	void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*next;
	int		count;

	if (!list || !(*list))
		return ;
	prev = *list;
	next = prev->next;
	count = 1;
	while (prev && next)
	{
		while (prev && next && comp(prev->content, next->content))
		{
			ft_lstdel_at(list, count, del);
			next = prev->next;
		}
		prev = next;
		if (prev)
			next = prev->next;
		count++;
	}
}

int		ft_lstremdup_str(void *prev, void *next)
{
	if (!prev || !next)
		return (0);
	if (ft_strcmp((char *)prev, (char *)next) == 0)
		return (1);
	else
		return (0);
}
