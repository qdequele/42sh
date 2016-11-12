/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_array_to_string(char **tab)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(1);
	while (tab[i])
	{
		if (i > 0)
			str = ft_strfjoin(str, " ");
		str = ft_strfjoin(str, tab[i]);
		i++;
	}
	return (str);
}
