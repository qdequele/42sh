/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:38:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static 	char 	*read_read()
{
	char buf[9];
	char *ret;

	ft_bzero(buf, 9);
	ret = NULL;
	ft_putstr_c(GREEN, "Read>");
	while (read(0, buf, 9))
	{
		if (BACK_SPACE)
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
char			*check_value(char opt, char *var_value)
{
	int i;
	int j;
	char *new_value;

	i = 0;
	j = 0;
	new_value = ft_strnew(1);
	while (var_value[i] != '\0')
	{
		if ((var_value[i] == '\\' && opt == 'r'))
			i++;
		else
		{
			new_value[j] = var_value[i];
			i++;
			j++;
		}
	}
	return (new_value);

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


int 			builtins_read(t_list **env, char **cmds)
{	
	char 	**var_value;
	char 	opt;
	char 	*ret;
	int 	nbr_var;
	int 	nbr_words;
	int 	i;

	(void)env;
	i = 1;
	opt = 0;
	if (cmds[i] && READ_OPT_R)
	{
		opt = 'r';
		i++;
	}
	ret = read_read();
	nbr_var = ft_count_raw_aoc(&cmds[i]);
	var_value = ft_strsplit(ret, ' ');
	nbr_words = count_words(ret, ' ');
	if (nbr_var == 1)
	{
		create_last_var(cmds[i], var_value, opt);
	}
	else if (nbr_var <= nbr_words)
	{
		i = 0;
		while (i++ <= nbr_var)
		{
			if (i == nbr_var)
				create_last_var(cmds[i], &var_value[i - 1], opt);
			else
				create_var(cmds[i], var_value[i - 1], opt);
		}
	}
	return (0);
}
