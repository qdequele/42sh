/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 18:52:25 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	display_quote_error(char c)
{
	char flag;

	if (c == '`')
		return (flag = 'b');
	else if (c == '"')
		return (flag = 'd');
	else if (c == '(')
		return (flag = 'p');
	else
		return (flag = 0);
}

int		print_error(char flag)
{
	t_prompt	*prompt;

	prompt = recover_shell()->prompt;
	if (flag)
		ft_putchar_c(GREEN, flag);
	ft_putstr_c(GREEN, "quote> ");
	prompt->p_pos = prompt->i_pos;
	return (0);
}

int		quote_close(char *str, char c)
{
	if (c == '(')
		c = ')';
	if (ft_strchr(str, c))
		return (1);
	else
		return (0);
}

void			read_quote_input(char quote)
{
	t_prompt	*prompt;
	t_shell		*shell;
	char		buf[8];
	t_status	status;
	t_status	nb_quote;

	shell = recover_shell();
	prompt = shell->prompt;
	shell->mode = QUOTE;
	prompt->p_length = get_quote_prompt_length(quote);
	add_char('\n');
	nb_quote = 0;
	ft_bzero(buf, 8);
	print_error(display_quote_error(quote));
	while (read(0, buf, 8))
	{
		if (buf[0] == quote)
			nb_quote++;
		status = prompt_find_function(buf);
		if (status == FOUND && nb_quote % 2 != 0)
		{
			add_char('\n');
			shell->mode = NORMAL;
			break ;
		}
		if (ENTER)
		{
			add_char('\n');
			print_error(display_quote_error(quote));
		}
		ft_bzero(buf, 8);
	}
}

int		check_quote(char *line)
{
	int		i;

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
