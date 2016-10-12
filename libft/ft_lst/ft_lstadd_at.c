/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:10:53 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 10:23:10 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_at(t_list **lst, t_list *new, int at)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = *lst;
	while (i <= (at - 1))
	{
		tmp = tmp->next;
		if (tmp == NULL)
			break ;
		i++;
	}
	if (tmp != NULL)
	{
		new->next = tmp->next;
		tmp->next = new;
	}
	else
	{
		ft_lstadd(lst, new);
	}
}