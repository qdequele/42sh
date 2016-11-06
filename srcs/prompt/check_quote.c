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

int 	quote_close(char *str, char c)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || (str[i] == ')' && c == '('))
			j++;
		if (j == 2)\
			return (1);
		i++;
	}
	return (0);
}

char	*remove_quote (char type, char *str)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	dst = ft_strnew(1);
	while (str[i] != '\0')
	{
		if (str[i] == type)
			k++;
		else if (str[i] != type && k != 2)
		{
			dst[j] = str[i];
			j++;
		}
		i++;
	}
	return (dst);
}
// TODO : actualiser la longueur du prompt et la i_position si error
int		check_quote(char *line)
{
	t_shell 	*shell;
	t_prompt 	*prompt;
	int 		i;
	int 		j;

	shell = recover_shell();
	prompt = shell->prompt;
	i = -1;
	j = 0;
	while (line[++i] != '\0')
	{
		if ((line[i] == '"' || line[i] == '\'' || line[i] == '(' || line[i] == ')' || line[i] == '`')
			&& prompt->quote_number < 2)
		{
			prompt->quote_type = line[i];
			if (quote_close(ft_strsub(line, i, ft_strlen(line)), prompt->quote_type) == 1)
			{
				line = remove_quote(prompt->quote_type, ft_strsub(line, i, ft_strlen(line)));
				prompt->quote_number = 0;
			}
			else
				return(display_quote_error(prompt->quote_type));
		}
	}
	return (1);
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

int		display_quote_error(char c)
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
	return (0);
}
