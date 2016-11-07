/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:12:26 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 19:39:18 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flag	g_flag_console_tab[NB_CONSOLE_FLAG] =
{
	{'c', &console_flag_c},
	{'d', &console_flag_d},
	{'s', &console_flag_s},
};

int			ft_console(const char *format, ...)
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
			comp += ft_console_checkflag(format[i], args);
		}
		else
		{
			ft_console_log_char(format[i]);
			comp++;
		}
		i++;
	}
	va_end(args);
	return (comp);
}

int			ft_console_checkflag(char flag, va_list args)
{
	int		i;
	char	*st_flag;

	st_flag = ft_strnew(1);
	st_flag[0] = flag;
	i = 0;
	if (flag == '%')
	{
		ft_console_log_char(flag);
		return (1);
	}
	while (i < NB_CONSOLE_FLAG)
	{
		if (ft_strcmp(st_flag, &g_flag_console_tab[i].key) == 0)
			return (g_flag_console_tab[i].ptrfunc(args));
		i++;
	}
	ft_console_log("Unknown command: %");
	ft_console_log(st_flag);
	ft_console_log("\n");
	return (0);
}
