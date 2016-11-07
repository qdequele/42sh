/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:18:37 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 12:32:58 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

int		ft_count_column_aoc(char **tab);
int		ft_count_column_aos(char ***tab);
int		ft_count_column_aoi(int **tab);
int		ft_count_raw_aoc(char **tab);
int		ft_count_raw_aos(char ***tab);
int		ft_count_raw_aoi(int **tab);
void	ft_free_aoc(char **arr);
void	ft_free_aoi(int **arr);
void	ft_free_aos(char ***arr);
char	***ft_join_aos(char ***last_array, char **to_add);
char	**ft_join_aoc(char **last_array, char *to_add);
int		**ft_join_aoi(int **last_array, int *to_add);
void	ft_print_aoc(char **array);
void	ft_print_aoi(int **array, int width, int height);
void	ft_print_aos(char ***array);
char	*ft_array_to_string(char **tab);

#endif
