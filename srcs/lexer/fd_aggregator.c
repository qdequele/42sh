/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_aggregator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/24 15:56:20 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_cmd	*parse_fd_aggregator(char *str)
{
	char 	*left;
	char 	*pattern;
	int 	fd;

	left = parse_left(str);
	pattern = ft_strtrim(ft_strsub(str, ft_strlen(left), ft_strlen(str)));
	fd = ft_atoi(&pattern[0]);
	return (build_redirection(left, " ", 1, fd, fd));
}
