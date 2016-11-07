/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_channel_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 04:10:04 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/19 20:24:55 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void		delete_char(void)
{
	tputs(tgoto(LESTR, 0, 0), 1, ft_tputs);
	tputs(DMSTR, 1, ft_tputs);
	tputs(DCSTR, 1, ft_tputs);
	tputs(EDSTR, 1, ft_tputs);
}

static char		*add_to_list(t_list **list, char *ret)
{
	ft_lstadd(list, ft_lstnew(ft_strtrim(ret), ft_strlen(ret)));
	ft_putstr("heredoc> ");
	free(ret);
	ret = ft_strnew(1);
	return (ret);
}

static void		print_on_fd(int *pipe_fd, t_list *list)
{
	char		**tab_var;
	int			i;

	i = 0;
	tab_var = list_to_tab(list);
	if (ft_lstcount(list) == 0)
		return ;
	while (tab_var[i])
	{
		write(pipe_fd[1], tab_var[i], ft_strlen(tab_var[i]));
		write(pipe_fd[1], "\n", 1);
		free(tab_var[i]);
		i++;
	}
	free(tab_var);
}

static void		assign_new_fd(t_process *p, int *pipe_fd, int channel)
{
	p->stdio[channel].fd = pipe_fd[0];
	p->stdio[channel].to_close = 1;
	close(pipe_fd[1]);
}

int				parse_heredoc_redir(t_process *p, int channel, char *target)
{
	t_list		*list;
	char		buf[8];
	char		*ret;
	int			pipe_fd[2];

	ret = NULL;
	list = NULL;
	ft_bzero(buf, 8);
	pipe(pipe_fd);
	ft_putstr("heredoc> ");
	while (read(0, buf, 8))
	{
		ft_putchar(buf[0]);
		ret = ft_freejoin(ret, buf);
		DELETE ? delete_char() : NULL ;
		if (ENTER && ft_strcmp(ft_strtrim(ret), target) != 0)
			ret = add_to_list(&list, ret);
		else if (ENTER)
		{
			print_on_fd(pipe_fd, list);
			break ;
		}
	}
	assign_new_fd(p, pipe_fd, channel);
	return (0);
}
