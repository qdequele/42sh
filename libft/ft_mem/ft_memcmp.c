/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:11:48 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 12:11:36 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (c1[i] == c2[i] && i < n - 1)
	{
		i++;
	}
	return (c1[i] - c2[i]);
}
