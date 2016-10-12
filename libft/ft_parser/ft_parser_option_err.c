/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_option_err.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:53:27 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 16:57:53 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*options_usage(t_option **l_options, int nb_opts)
{
	int		i;
	char	*usage;

	i = 0;
	usage = ft_strnew(nb_opts);
	while (i < nb_opts)
	{
		usage[i] = l_options[i]->name;
		i++;
	}
	return (usage);
}

void		option_illegal_err(t_option **l_options, int nb_opts, char opt,
	char *prog_name)
{
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage : ", 2);
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(" [", 2);
	ft_putstr_fd(options_usage(l_options, nb_opts), 2);
	ft_putendl_fd("]", 2);
}
