/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 21:38:12 by bjamin           ###   ########.fr       */
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
		return (flag = 1);
	else
		return (flag = 0);
}

int		print_error(char flag)
{
	if (flag == '(')
		ft_putstr_fd(">", 2);
	else if (flag)
		ft_putchar_fd(flag, 2);
	ft_putstr_fd("quote>", 2);
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
				free(&line);
				return (print_error(display_quote_error(line[i])));
			}
		}
		i++;
	}
	free(line);
	return (1);
}
