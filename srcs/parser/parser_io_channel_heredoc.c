/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_channel_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 04:10:04 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/20 18:29:13 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	char		*add_to_list(t_list **list, char *ret, int mode)
{
	char *tmp;

	if (!ret)
		ret = ft_strdup(" ");
	tmp = ft_strtrim(ret);
	ft_lstaddend(list, ft_lstnew(tmp, sizeof(char) * (ft_strlen(tmp) + 1)));
	free(tmp);
	free(ret);
	ret = NULL;
	if (mode)
		ft_putstr_c(GREEN, "heredoc> ");
	return (ret);
}

static	void		print_on_fd(int *pipe_fd, t_list **list)
{
	t_list		*cur;
	t_list		*tmp;
	char		*str;

	ft_putchar('\n');
	if (ft_lstcount(*list) == 0)
		return ;
	cur = *list;
	while (cur)
	{
		str = cur->content;
		write(pipe_fd[1], str, ft_strlen(str));
		write(pipe_fd[1], "\n", 1);
		free(str);
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

static	void		read_heredoc(char *b, char *target, int *pipe_fd)
{
	t_list	*list;
	char	*ret;

	ret = NULL;
	list = NULL;
	init_term(0);
	while (read(0, b, 4))
	{
		ft_putchar(b[0]);
		if (b[0] != '\n')
			ret = ft_freejoin(ret, b);
		if (ret && ((ft_strcmp(target, "EOF") == 0 && CTRL_D)
					|| (ft_strcmp(ret, target) == 0 && ENTER)))
		{
			free(ret);
			print_on_fd(pipe_fd, &list);
			break ;
		}
		if (ENTER)
			ret = add_to_list(&list, ret, 1);
		ft_bzero(b, 4);
	}
	reset_term();
	return ;
}

static	void		assign_new_fd(t_process *p, int *pipe_fd, int channel)
{
	p->stdio[channel].fd = pipe_fd[0];
	p->stdio[channel].to_close = 1;
	close(pipe_fd[1]);
}

int					parse_heredoc_redir(t_process *p, int channel, char *target)
{
	t_list		*list;
	char		b[4];
	int			pipe_fd[2];

	list = NULL;
	ft_bzero(b, 4);
	pipe(pipe_fd);
	ft_putstr_c(GREEN, "heredoc> ");
	read_heredoc(b, target, pipe_fd);
	assign_new_fd(p, pipe_fd, channel);
	return (0);
}
