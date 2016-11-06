/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:03:23 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 20:27:49 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbword;
	int		i;

	if (s == NULL)
		return (NULL);
	nbword = ft_wordcount((char const *)s, c);
	tab = (char **)malloc(sizeof(char *) * (nbword + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (nbword--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_wordlen((const char *)s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_wordlen((const char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char 		**str_split_str(char *str, char *cmp)
{
	int 	nb_match;
	char	**l_str;
	char 	**ret;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	if (str == NULL || cmp == NULL)
		return (NULL);
	nb_match = ft_nmatch(ft_strdup(str), ft_strdup(ft_strjoin(ft_strdup("*"), ft_strjoin(ft_strdup(cmp), ft_strdup("*")))));
	l_str = ft_strsplit(str, ' ');
	ret = (char **)malloc(sizeof(char *) * (nb_match + 2));
	ret[nb_match + 1] = NULL;
	if (nb_match == 0)
	{
		ret[0] = ft_strdup(str);
		return (ret);
	}
	if (ret == NULL)
		return (NULL);
	while(l_str[i])
	{
		if (ft_strcmp(ft_strdup(l_str[i]), ft_strdup(cmp)) == 0)
			j++;
		else
		{
			if (ret[j] == NULL)
				ret[j] = ft_strdup(l_str[i]);
			else
				ret[j] = ft_strdup(ft_strjoin(ft_strdup(ret[j]), ft_strjoin(ft_strdup(" "), ft_strdup(l_str[i]))));
		}
		i++;
	}
	return (ret);
}
