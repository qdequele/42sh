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
	elem = g_g_vars;
	fd = open("./ressources/vars", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd <= 0)
		return ;
	while (elem && elem->content)
	{
		var = elem->content;
		if (var->key != NULL && ft_strlen(var->key) != 0
				&& var->value != NULL)
		{
			ft_putstr_fd(var->key, fd);
			ft_putstr_fd("=", fd);
			ft_putendl_fd(var->value, fd);
		}
		elem = elem->next;
	}
	close(fd);
}

void	load_vars(void)
{
	int			fd;
	char		*line;
	char		*split[2];

	fd = open("./ressources/vars", O_RDWR, 0666);
	if (fd > 0)
	{
		while (ft_get_next_line(fd, &line) > 0)
		{
			split[0] = ft_strsub(line, 0, ft_strlen(line) -
				ft_strlen(ft_strchr(line, '=')));
			split[1] = (ft_strrchr(line, '=')) ?
				ft_strsub(line,
					ft_strlen(line) - ft_strlen(ft_strrchr(line, '=') + 1),
					ft_strlen(line) - ft_strlen(split[0])) : ft_strdup("");
			vars_add_or_modify(&g_g_vars, split[0], split[1]);
			free(line);
			free(split[0]);
			free(split[1]);
		}
		close(fd);
	}
	vars_add_or_modify(&g_l_vars, "?", "0");
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
