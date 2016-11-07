/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_separator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		is_token_and(char *line)
{
	if (*line == '&' && *(line + 1) == '&')
		return (2);
	return (0);
}

int		is_token_or(char *line)
{
	if (*line == '|' && *(line + 1) == '|')
		return (2);
	return (0);
}

int		is_token_semi_colon(char *line)
{
	return (*line == ';');
}

int		is_token_to_background(char *line)
{
	return (*line == '&');
}

int		is_token_pipe(char *line)
{
	return (*line == '|');
}
