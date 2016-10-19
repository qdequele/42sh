/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:27:47 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_cmd	*build_heredoc(char *left, t_list *list)
{
	t_heredoc *heredoc;

	heredoc = (t_heredoc*)malloc(sizeof(t_heredoc));
	heredoc->type = HEREDOC;
	heredoc->left = parse_cmd(left);
	heredoc->right = list;
	return ((t_cmd*)heredoc);
}

t_cmd	*parse_heredoc(char *complet_pipe)
{
	t_list 	*list_right;
	char	*left_cmd;

	left_cmd = body_left(complet_pipe, '<');
	list_right = heredoc_right(body_right(complet_pipe, '<'));
	return (build_heredoc(left_cmd, list_right));
}

t_list	*heredoc_right(char *s1)
{
	char		*buf;
	t_list		*list;
	char		*ret;

	ret = NULL;
	buf = ft_strnew(1);
	list = NULL;
	ft_putstr("heredoc> ");
	while (read(0, buf, 1))
	{
		ft_putchar(buf[0]);
		ret = ft_freejoin(ret, buf);
		if (ENTER)
		{
			if (ft_strcmp(ft_strtrim(ret), s1) == 0)
				break ;
			else
			{
				ft_lstadd(&list, ft_lstnew(ft_strtrim(ret), ft_strlen(ret)));
				ft_putstr("heredoc> ");
				ret = ft_strnew(1);
			}
		}
	}
	return (list);
}

void	print_stdout(t_heredoc *p_cmd, int *p)
{
	dup2(p[1], 1);
	close(p[0]);
	ft_lst_reverse(p_cmd->right);
	while (p_cmd->right)
	{
		ft_putendl_fd(p_cmd->right->content, 1);
		p_cmd->right = p_cmd->right->next;
	}
	exit(0);
}

void	exec_heredoc(t_cmd *cmd)
{
	t_heredoc	*p_cmd;
	int			p[2];
	int			pid[2];

	p_cmd = (t_heredoc*)cmd;
	if (pipe(p) == 0)
	{
		if ((pid[0] = fork()) == 0)
			print_stdout(p_cmd, p);
		else if ((pid[1] = fork()) == 0)
		{
			dup2(p[0], 0);
			close(p[1]);
			exec_cmd(p_cmd->left);
			exit(0);
		}
		close(p[0]);
		close(p[1]);
		waitpid(-1, 0, 0);
		waitpid(-1, 0, 0);
	}
	else
		exit(2);
}