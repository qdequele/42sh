/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:03:23 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/21 16:02:47 by qdequele         ###   ########.fr       */
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
	tab = (char **)malloc(sizeof(*tab) * nbword + 1);
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
	nb_match = ft_nmatch(str, ft_strfjoin(ft_strdup("* "), ft_strfjoin(ft_strdup(cmp), ft_strdup(" *"))));
	l_str = ft_strsplit(str, ' ');
	ret = (char **)malloc(sizeof(char *) * (nb_match + 1));
	if (ret == NULL)
		return (NULL);
	while(l_str[i])
	{
		if (ft_strcmp(l_str[i], cmp) == 0)
			j++;
		ret[j] = ft_strfjoin(ret[j], ft_strfjoin(ft_strdup(" "), l_str[i]));
		i++;
	}
	return (ret);
}
