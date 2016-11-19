/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:54:05 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	save_history(void)
{
	t_shell	*shell;
	int		index;
	int		fd;

	index = -1;
	shell = recover_shell();
	reset_history();
	fd = open("./ressources/history", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd > 0)
	{
		while (++index < ft_lstcount(shell->history) - 1)
		{
			ft_putstr_fd((char*)ft_lstget_at(shell->history,
				index)->content, fd);
			ft_putstr_fd("\n", fd);
		}
		close(fd);
	}
}

void	load_history(void)
{
	int			fd;
	char		*line;
	t_term		*term;

	term = recover_term();
	fd = open("./ressources/history", O_RDWR, 0666);
	if (fd > 0)
	{
		while (ft_get_next_line(fd, &line) > 0)
		{
			add_history(line);
			free(line);
		}
		close(fd);
	}
}

void	reset_history(void)
{
	int		fd;

	fd = open("./ressources/history", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd > 0)
	{
		ft_putstr_fd("", fd);
		close(fd);
	}
}
