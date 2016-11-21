/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:06:48 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/29 19:01:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void		check_lexer_error(char *token)
{
	ft_putstr_fd("42sh: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putendl_fd("`", 2);
	vars_add_or_modify(&g_vars, "?", "1");
}

static int		check_lexer_single_bg(t_list *token_list)
{
	t_token	*t;

	if (!token_list)
		return (1);
	t = token_list->content;
	if (!t)
		return (1);
	if (t->type == TO_BACKGROUND)
	{
		check_lexer_error("&");
		return (1);
	}
	if (t->type == SEMI_COLON)
	{
		check_lexer_error(";");
		return (1);
	}
	return (0);
}

static int		token_error(t_list *token, t_token *t)
{
	if (!t || (t && (t->type == PIPE || t->type == OR || t->type == AND)))
	{
		check_lexer_error("\\n");
		ft_lstdel(&token, &del_token);
		return (1);
	}
	return (0);
}

int				check_lexer(t_list *token_list)
{
	t_token		*t;
	t_token		*t_next;
	t_list		*token_list_tmp;

	t = NULL;
	token_list_tmp = token_list;
	if (!token_list || check_lexer_single_bg(token_list)
		|| token_error(token_list_tmp, token_list->content))
		return (1);
	while (token_list->next)
	{
		t = token_list->content;
		t_next = token_list->next->content;
		if (t->type == PIPE && t_next->type != CMD)
		{
			check_lexer_error("|");
			return (1);
		}
		if ((t->type == PIPE && t_next->type == OR) || (t->type == OR && t_next->type == PIPE))
		{
			check_lexer_error("|");
			return (1);
		}
		if ((t->type == AND && t_next->type == TO_BACKGROUND) || (t->type == TO_BACKGROUND && t_next->type == AND))
		{
			check_lexer_error("&");
			return (1);
		}
		if ((t->type == SEMI_COLON && t_next->type == SEMI_COLON))
		{
			check_lexer_error(";");
			return (1);
		}
		if ((t->type == SEMI_COLON && t_next->type != CMD))
		{
			check_lexer_error(";");
			return (1);
		}
		token_list = token_list->next;
	}
	if (token_error(token_list_tmp, token_list->content))
		return (1);
	return (0);
}
