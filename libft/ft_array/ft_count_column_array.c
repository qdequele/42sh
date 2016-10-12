/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_column_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/16 15:03:55 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** NAME : ft_count_column_aoc (unnoficial)
** DESCRIPTION : Compte le nombre de colonnes dans un tableau de caracteres
** PARAM : Le tableau de caractere dont il faut compter les colonnes
** RETURN : Le nombre de colonne dans le tableau
*/

int		ft_count_column_aoc(char **tab)
{
	int		i;

	i = 0;
	while (tab[0][i])
		i++;
	return (i);
}

/*
** NAME : ft_count_column_aos (unnoficial)
** DESCRIPTION : Compte le nombre de colonnes dans un tableau de chaine de
** caracteres
** PARAM : Le tableau de chaine de caractere dont il faut compter les colonnes
** RETURN : Le nombre de colonne dans le tableau
*/

int		ft_count_column_aos(char ***tab)
{
	int		i;

	i = 0;
	while (tab[0][i])
		i++;
	return (i);
}

/*
** NAME : ft_count_column_aoi (unnoficial)
** DESCRIPTION : Compte le nombre de colonnes dans un tableau d'entier
** PARAM : Le tableau d'entiers dont il faut compter les colonnes
** RETURN : Le nombre de colonne dans le tableau
*/

int		ft_count_column_aoi(int **tab)
{
	int		i;

	i = 0;
	while (tab[0][i])
		i++;
	return (i);
}
