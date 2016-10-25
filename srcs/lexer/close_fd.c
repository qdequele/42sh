/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:31:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>


char 	*parse_left_close_fd(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == '<' && ft_isdigit(str[i]))
			return (ft_strtrim(ft_strsub(str, 0 , i)));
		i++;
	}
	return (" ");
}

int 	parse_fd_close_fd(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) && str[i + 1] == '<')
			return (ft_atoi(&str[i]));
		i++;
	}
	return (0);
}

t_cmd	*parse_close_fd(char *str)
{
	char *left;
	int  fd;
	int mode;

	left = parse_left_close_fd(str);
	fd = parse_fd_close_fd(str);
	mode = 0;
	return (build_redirection(left, " ", mode, fd, 0));
}