/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:02:36 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 16:55:25 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	c2;

	i = 0;
	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (s2[i] == c2)
			return (void *)(&s2[i]);
		i++;
	}
	return (NULL);
}
