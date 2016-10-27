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

t_cmd	*parse_redirect_entry(char *cmd)
{
	char 	**body;
	int  	*fd;
	char 	*pattern;
	char 	*type_of;
	int 	mode;

	fd = (int*)malloc(sizeof(int) * 2);
	body = (char**)malloc(sizeof(char*) * 2);
	body [0]  = parse_left(cmd);
	body[1] = parse_right(cmd);
	pattern = ft_strtrim(ft_strsub(cmd, ft_strlen(body[0]) + 1, 1));
	fd = parse_fd(pattern);
	fd[0] = 0;
	type_of = parse_type(pattern);
	mode = parse_mode(pattern);
	// printf("left : [%s] | right : [%s] | mode : [%d] | pattern  : [%s] | type : [%s] | fd_left [%d] | fd_right [%d]\n", body[0], body[1], mode, pattern, type_of, fd[0], fd[1]);
	return (build_redirection(body, mode, fd, type_of));
}