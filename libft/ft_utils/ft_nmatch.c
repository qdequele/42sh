/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:07:43 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/21 16:03:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_nmatch(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1 != '\0')
			return (ft_nmatch(s1 + 1, s2) + ft_nmatch(s1, s2 + 1));
		if (*s1 == '\0')
			return (ft_nmatch(s1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		if (*s1 != '\0' && *s1 != '*')
			return (ft_nmatch(s1 + 1, s2 + 1));
		if (*s1 == '\0')
			return (1);
	}
	return (0);
}
