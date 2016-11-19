/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:19:59 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 19:27:49 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include <stdarg.h>
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
# define NB_PRINTF_FLAG 3
# define NB_CONSOLE_FLAG 3

typedef struct	s_flag
{
	char		key;
	int			(*ptrfunc)(va_list ap);
}				t_flag;

void			ft_print_n_time(char c, int n);
void			ft_print_n_time_fd(char c, int n, int fd);
void			ft_putchar(char c);
void			ft_putchar_c(char *color, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar_fd_c(char *color, char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl_fd_c(char *color, char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_c(char *color, int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_fd_c(char *color, int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_c(char *color, char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr_fd_c(char *color, char const *s, int fd);
void			ft_puttab(char **tab);
int				ft_printf(const char *format, ...);
int				ft_printf_checkflag(char flag, va_list args);
int				printf_flag_s(va_list ap);
int				printf_flag_c(va_list ap);
int				printf_flag_d(va_list ap);
int				ft_console(const char *format, ...);
int				ft_console_checkflag(char flag, va_list args);
int				console_flag_s(va_list ap);
int				console_flag_c(va_list ap);
int				console_flag_d(va_list ap);

#endif
