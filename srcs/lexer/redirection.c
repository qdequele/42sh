/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 18:59:15 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_cmd	*build_redirection(char **body, int mode, int *fd, char *type_of)
{
	t_redirection *redirection;

	redirection = (t_redirection*)malloc(sizeof(t_redirection));
	redirection->type = REDIRECTION;
	redirection->left = parse_cmd(body[0]);
	redirection->right = body[1];
	redirection->mode = mode;
	redirection->fd = fd;
	redirection->type_of = type_of;
	return ((t_cmd*)redirection);
}

void			exec_redirection(t_cmd *cmd)
{
	t_redirection		*rcmd;
	int					new_fd;
	int					old_fd;


	rcmd = (t_redirection*)cmd;
	new_fd = rcmd->fd[1];
	if (rcmd->fd[1] == -1)
	{
		dup2(new_fd, rcmd->fd[1]);
		exec_cmd(rcmd->left);
		return ;
	}
	if (rcmd->mode != 0  && (new_fd = open(rcmd->right, rcmd->mode, S_IRUSR | S_IWUSR)) == -1)
	{
		return ;
	}
	old_fd = dup(rcmd->fd[0]);
	dup2(new_fd, rcmd->fd[0]);
	exec_cmd(rcmd->left);
	dup2(old_fd, rcmd->fd[0]);

}
t_cmd	*parse_redirection(char *str)
{
	char 	**body;
	char 	*pattern;
	char 	*type_of;
	int  	*fd;
	int 	mode;

	fd = (int*)malloc(sizeof(int) * 2);
	body = (char**)malloc(sizeof(char *) * 2);
	body[0] = parse_left(str);
	body[1] = parse_right(str);
	pattern = ft_strtrim(ft_strsub(str, ft_strlen(body[0]), ft_strlen(str) - (ft_strlen(body[1]) + 1)));
	fd = parse_fd(pattern);
	mode = parse_mode(pattern);
	type_of = parse_type(pattern);
	return (build_redirection(body, mode, fd, type_of));

}
