/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:09:40 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 16:03:57 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	char			*ret;

	ret = dest;
	i = 0;
	while (*src && i < n)
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (ret);
}
