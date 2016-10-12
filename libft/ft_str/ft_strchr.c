/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:00:03 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/30 14:41:40 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** NAME : strchr
** DESCRIPTION : Rechercher un caractère dans une chaîne
** PARAM : s -> la chaire qui subit la recherche
** PARAM : c -> le caractere a rechercher
** RETURN : Le pointeur dur caractere recherché
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
** NAME : strchr_n
** DESCRIPTION : Rechercher un caractère dans une chaîne
** PARAM : s -> la chaire qui subit la recherche
** PARAM : c -> le caractere a rechercher
** RETURN : Le pointeur du caractere apres celui qui est recherché recherché
*/

char	*ft_strchr_n(const char *s, int c)
{
	while (*s && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
		return ((char *)++s);
	return (NULL);
}
