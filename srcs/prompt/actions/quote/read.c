/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/06 18:52:25 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char			display_quote_error(char c)
{
	char		flag;

	if (c == '`')
		return (flag = 'b');
	else if (c == '"')
		return (flag = 'd');
	else if (c == '(')
		return (flag = 'p');
	else
		return (flag = 0);
}

int				quote_close(char *str, char c)
{
	if (ft_strchr(str, c))
		return (1);
	else
		return (0);
}

static	void	read_quote(char *b, char quote)
{
	t_status	status;
	t_status	nb_quote;

	nb_quote = 0;
	if (quote == '(')
		quote = ')';
	while (read(0, b, 4))
	{
		if (b[0] == quote)
			nb_quote++;
		status = prompt_find_function(b);
		if (status == FOUND && nb_quote % 2 != 0)
		{
			add_char('\n');
			recover_shell()->mode = NORMAL;
			break ;
		}
		if (ENTER)
		{
			add_char('\n');
			print_error(display_quote_error(quote));
		}
		ft_bzero(b, 4);
	}
}

void			read_quote_input(char quote)
{
	t_prompt	*prompt;
	char		b[4];

	prompt = recover_shell()->prompt;
	recover_shell()->mode = QUOTE;
	prompt->p_length = get_quote_prompt_length(quote);
	add_char('\n');
	print_error(display_quote_error(quote));
	ft_bzero(b, 4);
	read_quote(b, quote);
}

int				check_quote(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'' || line[i] == '('
			|| line[i] == '`')
		{
			if (line[i + 1] && quote_close(&line[i + 1], line[i]) == 1)
			{
				free(line);
				return (1);
			}
			else
			{
				read_quote_input(line[i]);
				free(line);
				return (1);
			}
		}
		i++;
	}
	free(line);
	return (1);
}
