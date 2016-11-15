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

char			*ft_skip_char(char *str, char c)
{
	char		*new_str;
	int			i;
	int			nb_quotes;

	i = 0;
	nb_quotes = 0;
	new_str = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if ((size_t)(i + nb_quotes) > (ft_strlen(str)))
			break ; // fix leak invalid read size 1;
		while (str[i + nb_quotes] == c)
			nb_quotes++;
		if (str[i + nb_quotes])
			new_str[i] = str[i + nb_quotes];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
