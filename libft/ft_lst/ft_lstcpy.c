/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:14:23 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 11:39:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstcpy(t_list **dest, t_list *src)
{
	while (src)
	{
		ft_lstaddend(dest, ft_lstnew(src->content, src->content_size));
		src = src->next;
	}
}
