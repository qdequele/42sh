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

t_cmd	*build_redirection(char *left, char *right, int mode, int fd_left, int fd_right)
{
	t_redirection *redirection;

	redirection = (t_redirection*)malloc(sizeof(t_redirection));
	redirection->type = REDIRECTION;
	redirection->left = parse_cmd(left);
	redirection->right = right;
	redirection->mode = mode;
	redirection->fd_left = fd_left;
	redirection->fd_right = fd_right;\
	return ((t_cmd*)redirection);
}

void			exec_redirection(t_cmd *cmd)
{
	t_redirection		*rcmd;
	int					new_fd;
	int					old_fd;


	rcmd = (t_redirection*)cmd;
	new_fd = rcmd->fd_right;
	if (rcmd->fd_right == -1)
	{
		dup2(new_fd, rcmd->fd_left);
		exec_cmd(rcmd->left);
		return ;
	}
	if (rcmd->mode == 0 && (new_fd = open(rcmd->right, rcmd->mode, S_IRUSR | S_IWUSR)) == -1)
	{
		// error_no_file->right);
		printf("ERRROR\n");
		return ;
	}
	old_fd = dup(rcmd->fd_left);
	dup2(new_fd, rcmd->fd_left);
	close(new_fd);
	exec_cmd(rcmd->left);
	dup2(old_fd, rcmd->fd_left);
}
