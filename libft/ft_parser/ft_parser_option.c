/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:53:27 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 16:57:53 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		option_init(t_option **l_options, int nb_opts)
{
	int	i;

	i = 0;
	while (i < nb_opts)
	{
		l_options[i]->used = 0;
		i++;
	}
}

static int	option_used(t_option **l_options, int nb_opts, char opt)
{
	int	i;

	i = 0;
	while (i < nb_opts)
	{
		if (l_options[i]->name == opt)
		{
			l_options[i]->used = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	options_used(t_option **l_options, int nb_opts, char *opts,
	char *prog_name)
{
	int	i;

	i = 1;
	while (opts[i])
	{
		if (option_used(l_options, nb_opts, opts[i]) == 0)
		{
			option_illegal_err(l_options, nb_opts, opts[i], prog_name);
			return (0);
		}
		i++;
	}
	return (1);
}

int			options_parser(t_option **l_options, int nb_opts, char **cmds,
	char *prog_name)
{
	int	i;

	i = 1;
	while (cmds[i] && cmds[i][0] == '-')
	{
		if (cmds[i][0] == '-' && cmds[i][1] == '-' && !cmds[i][2])
		{
			i++;
			break ;
		}
		if ((cmds[i][0] == '-' && !cmds[i][1]))
			break ;
		else if (cmds[i][0] == '-' && cmds[i][1] == '-' && cmds[i][2])
		{
			option_illegal_err(l_options, nb_opts, '-', prog_name);
			return (0);
		}
		else if (cmds[i][0] == '-' && cmds[i][1])
		{
			if (options_used(l_options, nb_opts, cmds[i], prog_name) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
