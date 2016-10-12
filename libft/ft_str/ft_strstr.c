/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:41:50 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/05 15:45:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (s1[i] != '\0')
	{
		while (s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return (char *)(&s1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
