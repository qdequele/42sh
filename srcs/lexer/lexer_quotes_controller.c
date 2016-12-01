/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes_controller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:50:20 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:24:06 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	lexer_skip_double_quote(char *input)
{
	int		length;

	length = 1;
	input++;
	while (*input && *input != '"')
	{
		if (*input == '\\' && *(input + 1))
		{
			length += 2;
			input += 2;
		}
		length++;
		input++;
	}
	return (length);
}

static int	lexer_skip_single_quote(char *input)
{
	int		length;

	length = 1;
	input++;
	while (*input && *input != '\'')
	{
		length++;
		input++;
	}
	return (length);
}

int			lexer_skip_quotes(char *input)
{
	if (*input == '\'')
		return (lexer_skip_single_quote(input));
	if (*input == '"')
		return (lexer_skip_double_quote(input));
	return (0);
}
