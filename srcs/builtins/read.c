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

static int		check_key(char *str)
{
	int i;

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

static	void	read_bis(char **cmds, char **var_value, char opt, int nbr_var)
{
	int		i;
	char 	*tmp;

	i = 1;
	while (i <= nbr_var)
	{
		if (check_key(cmds[i]) == 1)
		{
			if (!var_value[i - 1] && i == nbr_var)
				create_last_var(cmds[i], NULL, opt);
			else if (i == nbr_var)
				create_last_var(cmds[i], &var_value[i - 1], opt);
			else
			{
				tmp = check_value(opt, var_value[i - 1]);
				vars_add_or_modify(&g_vars, cmds[i], tmp);
				free(tmp);
			}
		}
		i++;
	}
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

int				count_words(char *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

int				builtins_read(t_list **env, char **cmds)
{
	char	**var_value;
	int		nbr_var;
	char	opt;
	char	*ret;
	int		i;

	(void)env;
	i = 1;
	opt = 0;
	if (cmds[i] && READ_OPT_R)
	{
		opt = 'r';
		i++;
	}
	ret = read_read();
	if (ft_strlen(ret) == 0)
		return (1);
	var_value = ft_strsplit(ret, ' ');
	nbr_var = ft_count_raw_aoc(&cmds[i]);
	if ((nbr_var) == 1 && check_key(cmds[i]) == 1)
	{
		create_last_var(cmds[i], var_value, opt);
	}
	else
		read_bis(cmds, var_value, opt, nbr_var);
	ft_free_aoc(var_value);
	free(ret);
	return (0);
}
