/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:10:39 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/07 13:51:24 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_ptr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	new_ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_ptr)
		return (NULL);
	while (s[i])
	{
		new_ptr[i] = f(s[i]);
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}
