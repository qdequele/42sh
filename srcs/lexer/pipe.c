/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:31:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_cmd	*build_pipe(char *left, char *right)
{
	t_pipe *pipe;

	pipe = (t_pipe*)malloc(sizeof(t_pipe));
	pipe->type = PIPE;
	pipe->left = parse_cmd(left);
	pipe->right = parse_cmd(right);
	return ((t_cmd*)pipe);
}

t_cmd	*parse_pipe(char *complet_pipe)
{
	char	*left_cmd;
	char	*right_cmd;

	left_cmd = body_left(complet_pipe, '|');
	right_cmd = body_right(complet_pipe, '|');
	return (build_pipe(left_cmd, right_cmd));
}

void	exec_pipe(t_cmd *cmd)
{
	t_pipe	*p_cmd;
	int		pipes[2];
	int		pid[2];

	p_cmd = (t_pipe*)cmd;
	if (pipe(pipes) != 0)
		ft_putendl_fd("pipe error", 2);
	else if ((pid[0] = fork()) == 0)
	{
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[0]);
		exec_cmd(p_cmd->left);
		exit(0);
	}
	if ((pid[1] = fork()) == 0)
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[1]);
		exec_cmd(p_cmd->right);
		exit(0);
	}
	fork_close(pipes);
}
