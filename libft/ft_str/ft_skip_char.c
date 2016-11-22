/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:49:34 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 19:33:30 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		find_nb_char(char *str, char c)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

char			*ft_skip_char(char *str, char c)
{
	char		*new_str;
	int			i;
	int			nb_quotes;
	int			finded_quotes;

	i = 0;
	nb_quotes = 0;
	finded_quotes = find_nb_char(str, c) - (find_nb_char(str, c) % 2);
	if (!finded_quotes)
		return (str);
	new_str = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if ((size_t)(i + nb_quotes) > (ft_strlen(str)))
			break ;
		while (str[i + nb_quotes] == c && nb_quotes < finded_quotes)
			nb_quotes++;
		if (str[i + nb_quotes])
			new_str[i] = str[i + nb_quotes];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
