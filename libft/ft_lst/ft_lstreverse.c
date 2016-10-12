/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:17:19 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 11:33:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_reverse(t_list *root)
{
	t_list *new_root;
	t_list *next;

	new_root = NULL;
	next = NULL;
	while (root)
	{
		next = root->next;
		root->next = new_root;
		new_root = root;
		root = next;
	}
	return (new_root);
}
