/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:05:41 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/28 17:50:08 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_console_log(char *str)
{
	int new_file;

	new_file = open("./ressources/projet.log", O_RDWR | O_CREAT | O_APPEND);
	ft_putstr_fd(str, new_file);
	close(new_file);
}

void	ft_console_log_char(char c)
{
	int new_file;

	new_file = open("./ressources/projet.log", O_RDWR | O_CREAT | O_APPEND);
	ft_putchar_fd(c, new_file);
	close(new_file);
}

void	ft_console_log_num(int num)
{
	int new_file;

	new_file = open("./ressources/projet.log", O_RDWR | O_CREAT | O_APPEND);
	ft_putnbr_fd(num, new_file);
	close(new_file);
}

void	ft_console_log_line(const char *func, int line)
{
	ft_console_log(ft_strjoin(func, ft_strjoin(" : ",
		ft_strjoin(ft_itoa(line), "\n"))));
}

void	ft_console_log_clear(void)
{
	int new_file;

	new_file = open("./ressources/projet.log", O_RDWR | O_CREAT | O_TRUNC);
	ft_putstr_fd("", new_file);
	close(new_file);
}
