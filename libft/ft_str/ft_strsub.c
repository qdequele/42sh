/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:34:28 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/05 14:10:11 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	char			*ret;
	unsigned int	i;

	new_str = (char *)malloc(len + 1);
	if (!new_str || !s)
		return (NULL);
	i = start;
	ret = new_str;
	while ((i - start) < len)
	{
		*new_str = s[i];
		new_str++;
		i++;
	}
	*new_str = '\0';
	return (ret);
}
