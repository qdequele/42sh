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
	if (j == 1)
		return(M_WRITE_TRUNC);
	else if (j == 2)
		return (M_WRITE_APPEND);
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
	if (ft_isdigit(pattern[(ft_strlen(pattern) - 1)])
		&& pattern[(ft_strlen(pattern) - 2)] == '&')
		fd[1] = ft_atoi(&pattern[ft_strlen(pattern) - 1]);
	else
		fd[1] = -1;
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
		else if (str[i] == '>')
			return(ft_strtrim(ft_strsub(str, 0, i)));
		i++;
	}
	return (NULL);
}

char 	*parse_right(char *str)
{
	char 	*begin_str;
	int 	i;

	i = 1;
	begin_str = ft_strchr(str, '>');
	while (begin_str[i] != '\0')
	{
		if (begin_str[i - 1] && (begin_str[i - 1] == '>' || begin_str[i - 1] == '&') && (ft_isdigit(begin_str[i]) || begin_str[i] == ' '))
		{
			return(ft_strtrim(ft_strsub(begin_str, i + 1, ft_strlen(str))));
		}
		i++;
	}
	return (" ");
}

t_cmd	*parse_redirection(char *str)
{
	char 	*left;
	char 	*right;
	char 	*pattern;
	int  	*fd;
	int 	mode;

	fd = (int*)malloc(sizeof(int) * 2);
	left = parse_left(str);
	right = parse_right(str);
	pattern = ft_strtrim(ft_strsub(str, ft_strlen(left), ft_strlen(str) - (ft_strlen(right) + 2)));
	fd = parse_fd(pattern);
	mode = parse_mode(pattern);
	return (build_redirection(left, right, mode, fd[0], fd[1]));

}