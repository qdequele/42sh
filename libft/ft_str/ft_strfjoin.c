/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:58:37 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/30 14:42:34 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** NAME : strfjoin
** DESCRIPTION :  La fonction strfjoin() concatenne deux chaine de caractere
** dans une nouvelle chaine en s'assurant de free la premiere chaine a chaque
** fois
** PARAM : s1 -> la premiere chaine a concatenner
** PARAM : s2 -> la deuxieme chaine a concatenner
** RETURN : la chaine qui possedes les deux chaines concatenné
*/

char	*ft_strfjoin(char *s1, char *s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new_str);
}

char	*ft_strffjoin(char *s1, char *s2)
{
	char *new_str;

	if (!s1 || !s2)
		return (NULL);
	new_str = ft_strjoin(s1, s2);
	if (s1 && ft_strlen(s1) > 0)
		free(s1);
	if (s2 && ft_strlen(s2) > 0)
		free(s2);
	return (new_str);
}
