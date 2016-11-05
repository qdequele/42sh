/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_quotes_parent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:43:35 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/12 17:49:50 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		is_token_quote_back(char *line)
{
	
	if (*line == '`')
		return (1);
	return (0);
}

int		is_token_parent_close(char *line)
{
	
	if (*line == ')')
		return (1);
	return (0);
}

int		is_token_parent_open(char *line)
{
	
	if (*line == '(')
		return (1);
	return (0);
}
