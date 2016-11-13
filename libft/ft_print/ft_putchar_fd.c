/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:11:11 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 12:40:15 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putchar_fd_c(char *color, char c, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putchar_fd(c, fd);
	ft_putstr_fd("\e[0m", fd);
}
