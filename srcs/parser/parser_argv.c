/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:21:33 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/10 22:11:47 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>


char	*ft_str_replace_var(char *src, char *var, int *i)
{
	char	*begin;
	char	*end;
	char	*new_str;

	begin = ft_strdup(src);
	begin[*i - 1] = '\0';
	end = ft_strdup(src + *i + ft_strlen(var));
	new_str = ft_strfjoin(ft_strfjoin(begin, env_get(g_env, var)), end);
	*i += ft_strlen(new_str) - ft_strlen(src);
	free(src);
	free(end);
	free(var);
	return (new_str);
}

int		ft_is_var(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char	*replace_vars(char *str)
{
	int i;
	int end_dollar;
	int should_replace;

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

static size_t	count_args(const char *s)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == ' ') && !(s[i] == ' '))
			words++;
		i++;
	}
	return (words);
}

static char		*clear_str_space(char *s)
{
	char	*res;
	res = s;
	while (*s)
	{
		if (*s == '\'' || *s == '"' || *s == '`' || *s == '(')
		{
			s++;
			while (*s && *s != '\'' && *s != '"' && *s != '`' && *s != ')')
				s++;

		}
		if (ft_isspace(*s))
			*s = ' ';
		s++;
	}
	return (res);
}

char			*construct_job_command(t_list *process_list)
{
	char		*cmd;
	t_process	*p;
	int			i;

	cmd = NULL;
	while (process_list)
	{
		p = process_list->content;
		i = 0;
		while (p->argv && p->argv[i])
		{
			cmd = ft_strfjoin(cmd, p->argv[i++]);
			cmd = ft_strfjoin(cmd, " ");
		}
		if (process_list->next)
			cmd = ft_strfjoin(cmd, "| ");
		process_list = process_list->next;
	}
	return (cmd);
}

char			**parse_cmd_argv(t_process *p, char *cmd)
{
	char	**argv;
	char	**split;
	char	**start_split;
	int		i;

	i = 0;
	cmd = replace_vars(ft_strdup(cmd));
	clear_str_space(cmd);
	if (!(argv = malloc(sizeof(char *) * (count_args(cmd) + 1))) ||
		!(split = ft_strsplit(cmd, ' ')))
		return (NULL);
	start_split = split;
	while (*split)
	{
		if (is_token_redir(*split))
			split += parse_io_channel(p, split);
		else
			argv[i++] = ft_strdup(*split++);
	}
	argv[i] = NULL;
	free(cmd);
	ft_free_aoc(start_split);
	return (argv);
}
