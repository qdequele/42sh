/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/09 14:12:23 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static t_options	parse_options_init(void)
{
	t_options		options;

	options.start = 1;
	options.error = 0;
	options.options_counter = 0;
	options.options[0] = 0;
	return (options);
}

static int			parse_options_helper(t_options *options, char *m_options,
	char option)
{
	int				res;

	if (ft_is_in(m_options, option))
	{
		options->options[options->options_counter] = option;
		options->options_counter++;
		res = 1;
	}
	else
	{
		options->error = 1;
		options->error_char = option;
		res = 0;
	}
	options->options[options->options_counter] = 0;
	return (res);
}

t_options			t_options_parser(char **cmds, char *m_options)
{
	t_options		options;
	int				i;
	int				n;

	i = 1;
	options = parse_options_init();
	while (cmds[i] && cmds[i][0] == '-')
	{
		n = 1;
		if (ft_strcmp(cmds[i], "--") == 0)
		{
			options.start++;
			return (options);
		}
		while (cmds[i][n])
		{
			if (!parse_options_helper(&options, m_options, cmds[i][n]))
				return (options);
			n++;
		}
		options.start = ++i;
	}
	return (options);
}
