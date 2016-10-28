/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/27 14:43:16 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		sort_by_lexycography(t_list *node)
{
	t_list	*n_elem;

	n_elem = node->next;
	if (n_elem && ft_strlen((char *)(node->content)) > ft_strlen((char *)(n_elem->content)) > 0)
		return (1);
	return (0);
}