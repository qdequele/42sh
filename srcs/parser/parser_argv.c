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

static size_t	count_args(const char *s)
{
	size_t		words;
	size_t		i;

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
	char		*res;

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

char			*skip_token(char *arg)
{
	char		*new_arg;
	int			i;
	int			nb_quotes;

	i = 0;
	nb_quotes = 0;
	new_arg = ft_strnew(ft_strlen(arg));
	while (arg[i + nb_quotes])
	{
		if (arg[i + nb_quotes] == '\'' || arg[i + nb_quotes] == '"')
			nb_quotes++;
		if (arg[i + nb_quotes])
			new_arg[i] = arg[i + nb_quotes];
		i++;
	}
	new_arg[i] = '\0';
	free(arg);
	return (new_arg);
}

char			**parse_cmd_argv(t_process *p, char *cmd)
{
	char		**argv;
	char		**split;
	char		**start_split;
	int			i;

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
			argv[i++] = skip_token(ft_strdup(*split++));
	}
	argv[i] = NULL;
	free(cmd);
	ft_free_aoc(start_split);
	return (argv);
}
