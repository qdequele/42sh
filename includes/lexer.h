/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:22:50 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/20 14:16:14 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <ft_sh.h>

typedef enum			e_token_type
{
	CMD,
	OR,
	AND,
	SEMI_COLON,
	TO_BACKGROUND,
	PIPE,
	QUOTE_BACK,
	PARENT_OPEN,
	PARENT_CLOSE,
	TOKEN_TYPE_END_LIST
}						t_token_type;

typedef struct			s_token_matcher
{
	t_token_type		type;
	int					(*match_function)(char *);

}						t_token_matcher;

extern t_token_matcher	g_token_matcher[];

typedef struct			s_token
{
	t_token_type		type;
	void				*content;
}						t_token;

t_list					*input_to_token_list(char *input);
t_list					*new_token(t_token_type type, void *content);
void					del_token(void *token_void, size_t size_content);
int						is_token(char *str);
int						is_token_or(char *line);
int						is_token_and(char *line);
int						is_token_semi_colon(char *line);
int						is_token_to_background(char *line);
int						is_token_pipe(char *line);
int						is_token_quote_back(char *line);
int						is_token_redir(char *line);
int						is_token_redir_append_output(char *line);
int						is_token_redir_truncate_output(char *line);
int						is_token_redir_heredoc(char *line);
int						is_token_redir_get_input(char *line);
int						is_token_parent_open(char *line);
int						is_token_parent_close(char *line);
int						lexer_skip_quotes(char *input);
int						check_lexer(t_list *token_list);
char					*ft_remove_quote(char *word);

#endif
