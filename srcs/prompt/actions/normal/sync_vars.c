/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:54:05 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	save_vars(void)
{
	int		index;
	int		fd;
	t_list	*elem;
	t_var	*var;

	index = -1;
	reset_vars();
	elem = *vars_recover();
	fd = open("./ressources/vars", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd > 0)
	{
		while (elem && elem->content)
		{
			var = elem->content;
			if (var->key != NULL && ft_strlen(var->key) != 0
					&& var->value != NULL)
			{
				ft_putstr_fd(var->key, fd);
				ft_putstr_fd("=", fd);
				ft_putstr_fd(var->value, fd);
				ft_putstr_fd("\n", fd);
			}
			elem = elem->next;
		}
		close(fd);
	}
}

void	load_vars(void)
{
	int			fd;
	char		*line;
	char		**split;
	t_list		**vars;

	vars = vars_recover();
	fd = open("./ressources/vars", O_RDWR, 0666);
	if (fd > 0)
	{
		while (ft_get_next_line(fd, &line) > 0)
		{
			split = ft_strsplit(line, '=');
			vars_add_or_modify(vars_recover(), split[0], split[1]);
			free(line);
			ft_free_aoc(split);
		}
		close(fd);
	}
}

void	reset_vars(void)
{
	int		fd;

	fd = open("./ressources/vars", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd > 0)
	{
		ft_putstr_fd("", fd);
		close(fd);
	}
}
