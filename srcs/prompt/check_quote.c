/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_check_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/24 15:56:20 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char 	*remove_quote (char type, char *str)
{
	char 	*dst;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	dst = ft_strnew(1);
	while (str[i] != '\0')
	{
		if (str[i] != type)
		{
			dst[j] = str[i];
			j++;
		}
		i++;
	}
	return (dst);
}
// TODO : actualiser la longueur du prompt et la i_position si error
char 	*check_quote(char *line)
{
	t_shell 	*shell;
	t_prompt 	*prompt;
	int 		i;
	int 		j;

	shell = recover_shell();
	prompt = shell->prompt;
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		// if ((line[i] == ('"' | '`' | '\'' | '(')) && prompt->quote_number < 2)
		if ((line[i] == '"' || line[i] == '\'' || line[i] == '(' || line[i] == '`')
			&& prompt->quote_number < 2)
		{
			prompt->quote_type = line[i];
			prompt->quote_number++;
		}
		else if (prompt->quote_number == 2)
		{
			prompt->quote_type = line[i];
			prompt->quote_number = 1;
		}
		i++;
	}
	if (prompt->quote_number != 0 && prompt->quote_number % 2 != 0)
		display_quote_error(prompt->quote_type);
	else if (prompt->quote_number != 0)
	{
		line = remove_quote(prompt->quote_type, line);
		return (line);
	}
	else
		return (line);
	return (NULL);
}

void	print_error(char flag)
{
	if (flag && flag != '(')
		ft_putchar_fd(flag, 2);
	else if (flag == '(')
	{
		ft_putstr_fd(">", 2);
		return ;
	}
	ft_putstr_fd("quote>", 2);
	return ;

}

void	display_quote_error(char c)
{
	char flag;

	flag = 0;
	if (c == '`')
		flag = 'b';
	else if (c == '\'')
		flag = 0;
	else if (c == '"')
		flag = 'd';
	else if (c == '(' )
		flag = 1;
	print_error(flag);
}