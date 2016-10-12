/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:23:19 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 11:12:54 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	res = ft_lstnew(tmp->content, tmp->content_size);
	if (!res)
		return (NULL);
	tmp2 = res;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(tmp2->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		tmp2 = tmp2->next;
		lst = lst->next;
	}
	return (res);
}
