/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printf_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:12:26 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 19:11:10 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			console_flag_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_console_log(s);
	return (ft_strlen(s));
}

int			console_flag_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_console_log_char(c);
	return (1);
}

int			console_flag_d(va_list ap)
{
	char	*d;

	d = ft_itoa(va_arg(ap, int));
	ft_console_log(d);
	return (ft_strlen(d));
}
