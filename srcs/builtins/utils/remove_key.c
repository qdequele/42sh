/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 11:42:42 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	remove_key(t_list **head, char *key)
{
	t_list	*temp;
	t_list	*prev;

	temp = *head;
	if (temp != NULL && ft_strcmp(((t_env *)temp->content)->key, key) == 0)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && ft_strcmp(((t_env *)temp->content)->key, key) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
}
