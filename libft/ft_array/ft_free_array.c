/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:15:30 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/08 22:15:01 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** NAME : ft_free_aoc (unnoficial)
** DESCRIPTION : Libere un tableau de caractere
** PARAM : Le tableau a liberer
*/

void	ft_free_aoc(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

/*
** NAME : ft_free_aoi (unnoficial)
** DESCRIPTION : Libere un tableau d'entier
** PARAM : Le tableau a liberer
*/

void	ft_free_aoi(int **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
		}
		i++;
	}
	if (arr)
		free(arr);
}

/*
** NAME : ft_free_aos (unnoficial)
** DESCRIPTION : Libere un tableau de chaine de caractere
** PARAM : Le tableau a liberer
*/

void	ft_free_aos(char ***arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			free(arr[i][j]);
			j++;
		}
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}
