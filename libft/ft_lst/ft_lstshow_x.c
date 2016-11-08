/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshow_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstshow_x(t_list *list, int x)
{
	t_list	*cur;
	char	c;
	int		i;

	i = 0;
	cur = list;
	while (i < x)
	{
		cur = cur->next;
		i++;
	}
	while (cur)
	{
		c = *((char *)cur->content);
		ft_putchar(c);
		cur = cur->next;
	}
}
