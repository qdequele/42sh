/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/07 17:58:13 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char		*before_last_word(char *str, int c)
{
	char	*dup;
	int		i;

	if (str == NULL || str[0] == '\0' || ft_strchr(str, c) == NULL)
		return (ft_strdup("."));
	dup = ft_strdup(str);
	i = ft_strlen(dup) - 1;
	while (dup[i] && i >= 0)
	{
		if (dup[i] == c)
		{
			dup[i] = '\0';
			break ;
		}
		i--;
	}
	return (dup);
}

char		*get_last_word(char *str, int c)
{
	char	**arr;
	char	*ret;
	int		i;

	if (str == NULL || str[0] == '\0')
	{
		free(str);
		return (ft_strdup(""));
	}
	arr = ft_strsplit(str, c);
	i = 0;
	while (arr[i] && arr[i][0])
		i++;
	free(str);
	ret = ft_strdup(arr[i - 1]);
	ft_free_aoc(arr);
	return (ret);
}
