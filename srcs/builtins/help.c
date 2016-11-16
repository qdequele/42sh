/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:38:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int				builtins_help(t_list **env, char **cmds)
{
	int			new_file;
	char		*line;
	t_term		*term;

	UNUSED(cmds);
	UNUSED(env);
	term = recover_term();
	new_file = open("./ressources/help.txt", O_RDWR);
	if (new_file > 0)
	{
		while (ft_get_next_line(new_file, &line) > 0)
		{
			ft_putstr_fd(line, term->tty);
			ft_putchar_fd('\n', term->tty);
			free(line);
		}
		close(new_file);
		return (0);
	}
	return (1);
}
