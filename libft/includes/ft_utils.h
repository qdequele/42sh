/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:19:53 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/29 15:10:24 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# define BUFF_SIZE 64
# define __DEBUG__ ft_console_log_line(__FUNCTION__, __LINE__);

typedef struct	s_color {
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_gnl
{
	char		b[BUFF_SIZE + 1];
	char		*str;
	int			ret;
}				t_gnl;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
t_color			*ft_create_color_rgb(int r, int g, int b);
t_color			*ft_create_color_hex(int hex_color);
int				ft_get_next_line(int const fd, char **line);
char			*ft_itoa(int n);
char			*ft_itoa_base(int nb, int base);
int				ft_nbrlen(int nb);
int				ft_nbrlen_base(int nb, int base);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_wordcount(char const *s, char c);
int				ft_wordlen(char const *s, char c);
void			ft_console_log(char *str);
void			ft_console_log_char(char c);
void			ft_console_log_num(int num);
void			ft_console_log_line(const char *func, int line);
void			ft_console_log_clear(void);
int				ft_match(char *s1, char *s2);
int				ft_nmatch(char *s1, char *s2);

#endif
