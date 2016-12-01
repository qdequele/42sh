/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_asserts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 00:31:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:23:47 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			parser_assert_linker(t_token *t)
{
	if (!t)
		return (0);
	if (t->type == OR || t->type == AND || t->type == SEMI_COLON ||
		t->type == TO_BACKGROUND)
		return (1);
	return (0);
}

int			parser_assert_pipe(t_token *t)
{
	if (t && t->type == PIPE)
		return (1);
	return (0);
}

int			parser_assert_cmd(t_token *t)
{
	if (t && t->type == CMD)
		return (1);
	return (0);
}
