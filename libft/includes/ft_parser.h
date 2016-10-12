/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:20:03 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/16 11:24:41 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

typedef struct	s_option
{
	char		name;
	int			used;
}				t_option;

void			option_illegal_err(t_option **l_options, int nb_opts,
	char opt, char *prog_name);
int				options_parser(t_option **l_options, int nb_opts,
	char **cmds, char *prog_name);
void			option_init(t_option **l_options, int nb_opts);

#endif
