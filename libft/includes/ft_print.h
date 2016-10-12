/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:19:59 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/16 11:24:58 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define LIGHT_GREY "\e[37m"
# define DARK_GREY "\e[90m"
# define LIGHT_RED "\e[91m"
# define LIGHT_GREEN "\e[92m"
# define LIGHT_YELLOW "\e[93m"
# define LIGHT_BLUE "\e[94m"
# define LIGHT_MAGENTA "\e[95m"
# define LIGHT_CYAN "\e[96m"

void	ft_print_n_time(char c, int n);
void	ft_print_n_time_fd(char c, int n, int fd);
void	ft_putchar(char c);
void	ft_putchar_c(char *color, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_c(char *color, int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_c(char *color, char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_puttab(char **tab);

#endif
