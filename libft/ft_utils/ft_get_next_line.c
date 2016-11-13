/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 11:21:59 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/16 11:29:18 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_gnl_clear(int ret_int, char *str, char *b, int ret)
{
	str = NULL;
	b[0] = '\0';
	ret = 0;
	(void)ret;
	(void)str;
	return (ret_int);
}

int			ft_get_next_line(int const fd, char **line)
{
	static t_gnl	g[256];

	if (fd < 0 || BUFF_SIZE <= 0 || g[fd].ret == -1 || fd > 255)
		return (-1);
	g[fd].str = (!g[fd].str) ? ft_strnew(BUFF_SIZE) : g[fd].str;
	if (!ft_strchr(g[fd].str, '\n'))
	{
		if ((g[fd].ret = read(fd, g[fd].b, BUFF_SIZE)) == 0)
			return (ft_strlen(g[fd].str) > 0) ?
			ft_strcut(line, &(g[fd].str), '\0') :
			ft_gnl_clear(0, g[fd].str, g[fd].b, g[fd].ret);
		if (g[fd].ret < 0)
			return (ft_gnl_clear(-1, g[fd].str, g[fd].b, g[fd].ret));
		g[fd].b[g[fd].ret] = '\0';
		g[fd].str = ft_strfjoin(g[fd].str, g[fd].b);
		return (ft_get_next_line(fd, line));
	}
	else
		return (ft_strcut(line, &(g[fd].str), '\n'));
}
