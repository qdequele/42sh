/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:49:34 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/28 19:40:03 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_freejoin(char *s1, char *s2)
{
	char *ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	if (s2 == NULL)
	{
		ret = (ft_strdup(s1));
		ft_strdel(&(s1));
		return (ret);
	}
	if (s1 != NULL && s2 != NULL)
	{
		ret = (ft_strjoin(s1, s2));
		ft_strdel(&(s1));
		return (ret);
	}
	return (NULL);
}
