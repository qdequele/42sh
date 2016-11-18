/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:21:33 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/10 22:34:25 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char			*ft_str_replace_var(char *src, char *var, int *i)
{
	char		*begin;
	char		*end;
	char		*new_str;
	char		*new_var;

	begin = ft_strdup(src);
	begin[*i - 1] = '\0';
	end = ft_strdup(src + *i + ft_strlen(var));
	new_var = env_get(g_env, var);
	if (!new_var || ft_strlen(new_var) == 0)
		new_var = vars_get(g_vars, var);
	if (!new_var || ft_strlen(new_var) == 0)
		new_var = "";
	if (ft_strlen(new_var) > 0)
		new_str = ft_strfjoin(ft_strfjoin(begin, new_var), end);
	else
	{
		new_str = ft_strdup(" ");
		free(begin);
	}
	*i += ft_strlen(new_str) - ft_strlen(src);
	free(src);
	free(end);
	free(var);
	return (new_str);
}

int				ft_is_var(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char			*replace_vars(char *str)
{
	int			i;
	int			end_dollar;
	int			should_replace;

	i = 0;
	should_replace = 1;
	end_dollar = i;
	while (str[i])
	{
		if (should_replace && str[i] == '\'')
			should_replace = 0;
		else if (str[i] == '\'')
			should_replace = 1;
		if (should_replace && str[i] == '$')
		{
			i++;
			end_dollar = i;
			while (ft_is_var(str[end_dollar]))
				end_dollar++;
			str = ft_str_replace_var(str,
				ft_strsub(str, i, end_dollar - i), &i);
		}
		i++;
	}
	return (str);
}
