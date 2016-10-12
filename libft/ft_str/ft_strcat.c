/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:47:18 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/30 14:41:50 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** NAME : strcat
** DESCRIPTION :  La fonction strcat() ajoute la chaîne src à la fin de la
** chaîne dest en écrasant le caractère nul (« \0 ») à la fin de dest, puis
** en ajoutant un nouveau caractère nul final. Les chaînes ne doivent pas se
** chevaucher, et la chaîne dest doit être assez grande pour accueillir le
** résultat.
** PARAM : dest -> la chaine de destination
** PARAM : src -> la chaine de source
** RETURN : la chaine de destination
*/

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
