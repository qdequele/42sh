/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/08 22:26:40 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	void	more_key_than_value(char **v, char **cmds, int i, int o)
{
	char	*simple_quoted;
	char	*double_quoted;
	char	*without_quote;

	without_quote = (o == 1) ? ft_skip_char(ft_array_to_string(&v[i - 1]),
		'\\') : ft_array_to_string(&v[i - 1]);
	simple_quoted = ft_strjoin("'", without_quote);
	double_quoted = ft_strfjoin(simple_quoted, "'");
	vars_add_or_modify(&g_vars, cmds[i + o - 1], double_quoted);
	free(without_quote);
}

static	int		ck(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]))
		{
			ft_putstr_fd("42sh : not an identifier : ", 2);
			ft_putendl_fd(str, 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static	char	*read_read(void)
{
	char	b[9];
	char	*ret;
	char	*tmp;

	ft_bzero(b, 9);
	ret = ft_strdup("");
	ft_putstr_c(GREEN, "Read> ");
	while (read(0, b, 9) && !ENTER)
	{
		if (BACK_SPACE && ret && ft_strlen(ret) > 0)
		{
			tputs(tgoto(LESTR, 0, 0), 1, ft_tputs);
			tputs(DCSTR, 1, ft_tputs);
			tmp = ft_strsub(ret, 0, ft_strlen(ret) - 1);
			free(ret);
			ret = tmp;
		}
		else
		{
			ft_putchar(b[0]);
			ret = ft_strfjoin(ret, b);
		}
	}
	ft_putchar('\n');
	return (ret);
}

int				builtins_read(t_list **env, char **cmds)
{
	char	**v;
	int		o;
	int		i;
	char 	*read;

	o = (*env && cmds[1] && READ_OPT_R) ? 2 : 1;
	i = (o == 2) ? 0 : -1;
	read = read_read();
	v = ft_strsplit(read, ' ');
	free(read);
	while (cmds[++i + o] && ft_strlen(cmds[i + o]) > 0 && ck(cmds[i + o]))
	{
		printf("cmds[i+o] = [%s]\n", cmds[i+o]);
		v[i] = (o == 1 && v[i]) ? ft_skip_char(v[i], '\\') : v[i];
		if (v[i])
			vars_add_or_modify(&g_vars, cmds[i + o], v[i]);
		else
			vars_add_or_modify(&g_vars, cmds[i + o], " ");
	}
	if (cmds[o] && i <= ft_count_raw_aoc(v) && v[i])
		more_key_than_value(v, cmds, i, o);
	if (v)
		ft_free_aoc(v);
	return (0);
}
