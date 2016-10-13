/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:41:01 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:41:02 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstget_at(t_list *lst, int at)
{
	int i;

	i = 0;
	while (lst)
	{
		if (i == at)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
