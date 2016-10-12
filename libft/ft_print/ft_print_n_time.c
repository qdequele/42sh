/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:12:26 by qdequele          #+#    #+#             */
/*   Updated: 2015/11/24 14:21:19 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_print_n_time(char c, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}

void		ft_print_n_time_fd(char c, int n, int fd)
{
	int	i;

	i = 1;
	while (i < n)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
}
