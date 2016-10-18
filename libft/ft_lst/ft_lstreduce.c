/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:23:19 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 11:12:54 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstreduce(t_list *lst, int (*f)(t_list *elem))
{
	t_list	*res;

	if (!lst || !f)
		return (NULL);
    res = NULL;
	while (lst)
	{
        ft_console_log("ft_lstreduce : 1\n");
		if (f(lst) && lst != NULL)
        {
            ft_console_log("ft_lstreduce : 2\n");
            ft_lstaddend(&res, lst);
            ft_console_log("ft_lstreduce : 3\n");
        }
        lst = lst->next;
        ft_console_log("ft_lstreduce : 4\n");
	}
    ft_console_log("ft_lstreduce : 5\n");
	return (res);
}