/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:15:30 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 12:36:15 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** NAME : strcut (unofficial)
** DESCRIPTION : La fonction ft_strcut() coupe la chaine au caractere 'c'
** met dans 's1' le debut de la chaine et dans 's2' le reste. La chaine de
** depart qui aura l'origine sera 's2'
** PARAM : s1 -> la chaine dans laquel sera mis le debut de la chaine tronque
** PARAM : s2 -> la chaine dans laquel sera mis la fin de la chaine tronque
** RETURN : return always 1 when the function is finished
*/

int		ft_strcut(char **s1, char **s2, char c)
{
	char	*tmp;
	char	*ret;
	size_t	len;

	len = 0;
	ret = ft_strdup(*s2);
	while (ret[len] && ret[len] != c)
		len++;
	ret[len] = 0;
	*s1 = ret;
	tmp = ft_strsub(*s2, ft_strlen(*s1) + 1, ft_strlen(*s2) - ft_strlen(*s1));
	if (s2 && *s2)
		free(*s2);
	*s2 = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	return (1);
}

char	*ft_strcut_before(char **str, char c)
{
	char	**tab;

	tab = ft_strsplit(*str, c);
	return (ft_strdup(tab[0]));
}

char	*ft_strcut_after(char **str, char c)
{
	char	**tab;
	char	*after;
	int		i;

	i = 1;
	tab = ft_strsplit(*str, c);
	if (tab[i])
		after = ft_strdup(tab[i]);
	i++;
	while (tab[i])
	{
		ft_strfjoin(ft_strfjoin(after, &c), tab[i]);
		i++;
	}
	return (after);
}
