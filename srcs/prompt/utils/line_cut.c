/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 13:06:01 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

/*
** private
** DESCRIPTION  : Donne le dernier mot d'une ligne très pratique pour autocompleter ce mot
** EXPLICATIONS : Utilise strsplit pour couper la phrase en mot et renvoie le dernier
*/
char *before_last_word(char *str, int c)
{
	char 	*dup;
	int 	i;
	
	if (str == NULL || str[0] == '\0' || ft_strchr(str, c) == NULL)
		return (ft_strdup("."));
	dup = ft_strdup(str);
	
	i = ft_strlen(dup) - 1;
	while (dup[i] && i >=0)
	{
		if (dup[i] == c)
		{
			dup[i] = '\0';
			break;
		}
		i--;
	}
	return (dup);
}

/*
** public
** DESCRIPTION  : Donne le dernier mot d'une ligne très pratique pour autocompleter ce mot
** EXPLICATIONS : Utilise strsplit pour couper la phrase en mot et renvoie le dernier
*/
char *get_last_word(char *str, int c)
{
	char 	**tab;
	int 	i;
	
	if (str == NULL || str[0] == '\0')
		return (ft_strdup(""));
	tab = ft_strsplit(str, c);
	i = 0;
	while (tab[i] && tab[i][0])
		i++;
	return (tab[i - 1]);
}
