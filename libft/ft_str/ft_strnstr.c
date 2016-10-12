/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:15:08 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 16:54:11 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (s1[i] != '\0' && i < n)
	{
		k = i;
		while (s1[k] == s2[j] && k < n)
		{
			k++;
			j++;
			if (s2[j] == '\0')
				return (char *)(&s1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
