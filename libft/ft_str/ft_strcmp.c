/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:27:56 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/30 14:41:27 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** NAME : strcmp
** DESCRIPTION : La fonction strcmp() compare les deux chaînes s1 et s2. Elle
** renvoie un entier négatif, nul, ou positif, si s1 est respectivement
** inférieure, égale ou supérieure à s2.
** PARAM : s1 -> la premiere chaine à comparé
** PARAM : s2 -> la deuxieme chaine à comparé
** RETURN : entier positif, nul, ou negatif
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
