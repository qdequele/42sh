/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:31:13 by qdequele         ###   ########.fr       */
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
	printf("DEBUT EXEC REDIRECTION\n");
	printf("New_fd = %d\n", rcmd->fd[1]);
	if (rcmd->fd[1] == -1)
	{
		dup2(new_fd, rcmd->fd[1]);
		exec_cmd(rcmd->left);
		return ;
	}
	if (rcmd->mode != 0  && (new_fd = open(rcmd->right, rcmd->mode, S_IRUSR | S_IWUSR)) == -1)
	{
		// error_no_file->right);
		printf("ERRROR\n");
		return ;
	}
	old_fd = dup(rcmd->fd[0]);
	printf("%d = dup(%d)\n", old_fd, rcmd->fd[0]);
	// printf("1.1 Old : [%d] New : [%d] - fd[0] : [%d] | fd[1] : [%d]\n", old_fd, new_fd, rcmd->fd[0], rcmd->fd[1]);
	printf("dup2(new_fd, rcmd->fd[0]) -- dup2(%d, %d)\n", new_fd, rcmd->fd[0]);
	dup2(new_fd, rcmd->fd[0]);
	// close(new_fd);
	printf("exec_cmd(%s)\n", (char*)rcmd->left);
	exec_cmd(rcmd->left);
	printf("dup2(old_fd, rcmd->fd[0]) -- dup2(%d, %d)\n", old_fd, rcmd->fd[0]);
	dup2(old_fd, rcmd->fd[0]);

}

t_cmd	*parse_redirection(char *str)
{
	char 	**body;
	char 	*pattern;
	char 	*type_of;
	int  	*fd;
	int 	mode;

	printf("DEBUT PARSE REDIRECTION\n");
	fd = (int*)malloc(sizeof(int) * 2);
	body = (char**)malloc(sizeof(char *) * 2);
	body[0] = parse_left(str);
	body[1] = parse_right(str);
	pattern = ft_strtrim(ft_strsub(str, ft_strlen(body[0]), ft_strlen(str) - (ft_strlen(body[1]) + 1)));
	fd = parse_fd(pattern);
	mode = parse_mode(pattern);
	type_of = parse_type(pattern);
	// printf("left : [%s] | right : [%s] | mode : [%d] | pattern  : [%s] | type : [%s] | fd[0] [%d] | fd[1] [%d]\n", body[0], body[1], mode, pattern, type_of, fd[0], fd[1]);
	return (build_redirection(body, mode, fd, type_of));

}