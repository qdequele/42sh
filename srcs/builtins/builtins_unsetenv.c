/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/12 16:15:56 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

static void	env_remove_one(t_list **head, char *key)
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

int			builtins_unsetenv(t_list **env, char **cmds)
{
	int		i;

	i = 1;
	while (cmds[i])
	{
		env_remove_one(env, cmds[i]);
		i++;
	}
	g_env = *env;
	return (0);
}
