/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:31:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char 	*parse_type(char *pattern)
{
	if (ft_strchr(pattern, '-'))
		return ("CLOSE");
	else if (ft_strchr(pattern, '&'))
		return ("MODIFY");
	else
		return ("REDIRECTION");
}

int 	parse_mode(char *pattern)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (pattern[i] != '\0')
	{
		if (pattern[i] == '>')
			j++;
		i++;
	}
	if (j == 1 && ft_strchr(pattern, '&') == NULL)
	{
		return(M_WRITE_TRUNC);
	}
	else if (j == 2)
		return (M_WRITE_APPEND);
	else if (ft_strchr(pattern, '<'))
	{
		return (M_READ);
	}
	else
		return (0);
}

int 	*parse_fd(char *pattern)
{
	int *fd;

	fd = (int*)malloc(sizeof(int) * 2);
	if (ft_isdigit(pattern[0]))
		fd[0] = ft_atoi(&pattern[0]);
	else
		fd[0] = 1;
	if (ft_isdigit(pattern[(ft_strlen(pattern) - 1)]))
		fd[1] = ft_atoi(&pattern[ft_strlen(pattern) - 1]);
	else 
		fd[1] = fd[0];
	return (fd);
}

char 	*parse_left(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) && str[i + 1] && (str[i + 1] == '>' || str[i + 1] == '<'))
			return(ft_strtrim(ft_strsub(str, 0, i)));
		else if (str[i] == '>' || str[i] == '<')
			return(ft_strtrim(ft_strsub(str, 0, i)));
		i++;
	}
	return (" ");
}

char 	*parse_right(char *str)
{
	char 	*begin_str;
	int 	i;

	i = 1;
	if ((begin_str = ft_strchr(str, '>')) == NULL)
		begin_str = ft_strchr(str, '<');
	while (begin_str[i] != '\0')
	{
		if (begin_str[i - 1] && (begin_str[i - 1] == '>' || begin_str[i - 1] == '&' || begin_str[i - 1] == '<') && (ft_isdigit(begin_str[i]) || begin_str[i] == ' '))
		{
			return(ft_strtrim(ft_strsub(begin_str, i + 1, ft_strlen(str))));
		}
		i++;
	}
	return (" ");
}
