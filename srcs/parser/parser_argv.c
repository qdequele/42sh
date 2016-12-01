/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 19:21:33 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:23:46 by bjamin           ###   ########.fr       */
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
		if ((i == 0 || s[i - 1] == 1) && !(s[i] == 1))
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
			*s = 1;
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

char			**assert_argv(char *cmd, char ***argv)
{
	char		**s;

	if (!(*argv = malloc(sizeof(char *) * (count_args(cmd) + 1))))
	{
		free(cmd);
		return (NULL);
	}
	if (!(s = ft_strsplit(cmd, 1)))
	{
		free(cmd);
		free(*argv);
		return (NULL);
	}
	return (s);
}

char			**parse_cmd_argv(t_process *p, char *cmd)
{
	char		**argv;
	char		**s;
	char		**start_split;
	int			i;

	i = 0;
	cmd = clear_str_space(replace_vars(ft_strdup(cmd)));
	if (!(s = assert_argv(cmd, &argv)))
		return (NULL);
	start_split = s;
	while (*s)
	{
		if (is_token_redir(*s))
			s += parse_io_channel(p, s);
		else
			argv[i++] = ft_skip_char(ft_skip_char(ft_strdup(*s++), '"'), '\'');
	}
	argv[i] = NULL;
	free(cmd);
	ft_free_aoc(start_split);
	return (argv);
}
