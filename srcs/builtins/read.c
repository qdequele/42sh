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

static int		ck(char *str)
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
	char buf[9];
	char *ret;

	ft_bzero(buf, 9);
	ret = NULL;
	ft_putstr_c(GREEN, "Read>");
	while (read(0, buf, 9))
	{
		if (BACK_SPACE && ret && ft_strlen(ret) > 0)
		{
			tputs(tgoto(LESTR, 0, 0), 1, ft_tputs);
			tputs(DMSTR, 1, ft_tputs);
			tputs(DCSTR, 1, ft_tputs);
			tputs(EDSTR, 1, ft_tputs);
			ret = ft_strsub(ret, 0, ft_strlen(ret) - 1);
		}
		else
		{
			ft_putchar(buf[0]);
			ret = ft_freejoin(ret, buf);
		}
		if (ENTER)
			return (ret);
	}
	return (ret);
}

int				builtins_read(t_list **env, char **cmds)
{
	char	**v;
	char	*last;
	int		o;
	int		i;

	o = (*env && cmds[1] && READ_OPT_R) ? 2 : 1;
	i = (o == 2) ? 0 : -1;
	v = ft_strsplit(read_read(), ' ');
	while (cmds[++i + o] && ft_strlen(cmds[i + o]) > 0 && ck(cmds[i + o]))
	{
		v[i] = (o == 1 && v[i]) ? ft_skip_char(v[i], '\\') : v[i];
		if (v[i])
			vars_add_or_modify(&g_vars, cmds[i + o], ft_strdup(v[i]));
		else
			vars_add_or_modify(&g_vars, cmds[i + o], ft_strdup(" "));
	}
	if (v[i])
	{
		last = (o == 1) ? ft_skip_char(ft_array_to_string(&v[i - 1]), '\\')
		: ft_array_to_string(&v[i - 1]);
		last[ft_strlen(last) - 1] = '\0';
		vars_add_or_modify(&g_vars, cmds[i + o - 1], last);
	}
	if (v)
		ft_free_aoc(v);
	return (0);
}
