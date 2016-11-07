/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:12:26 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 19:52:27 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flag	g_flag_printf_tab[NB_PRINTF_FLAG] =
{
	{'c', &printf_flag_c},
	{'d', &printf_flag_d},
	{'s', &printf_flag_s},
};

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		comp;

	i = 0;
	comp = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i])
		{
			i++;
			comp += ft_printf_checkflag(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			comp++;
		}
		i++;
	}
	va_end(args);
	return (comp);
}

int			ft_printf_checkflag(char flag, va_list args)
{
	int		i;
	char	*st_flag;

	st_flag = ft_strnew(1);
	st_flag[0] = flag;
	i = 0;
	if (flag == '%')
	{
		ft_putchar(flag);
		return (1);
	}
	while (i < NB_PRINTF_FLAG)
	{
		if (ft_strcmp(st_flag, &g_flag_printf_tab[i].key) == 0)
			return (g_flag_printf_tab[i].ptrfunc(args));
		i++;
	}
	ft_putstr("Unknown command: %");
	ft_putendl(st_flag);
	return (0);
}
