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

void	create_var(char *var_name, char *var_value)
{
	char 	**set_env;

	set_env = (char**)malloc(sizeof(char*) * 3);
	set_env[0] = "setenv";
	set_env[1] = ft_strtrim(var_name);
	set_env[2] = ft_strtrim(var_value);
	builtins_setenv(&g_env, set_env);
}

void	create_last_var(char *var_name, char **var_value)
{
	char 	*last_var;
	int 	i;

	i = 0;
	while (var_value[i])
	{
		if (i > 0)
			last_var = ft_freejoin(last_var, " ");
		last_var = ft_freejoin(last_var, var_value[i]);
		i++;
	}
	create_var(var_name, last_var);
}

int		count_words(char *s, char c)
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


int 	builtins_read(t_list **env, char **cmds)
{
	char 	buf[9];
	char 	*ret;
	char 	**var_value;
	int 	nbr_var;
	int 	nbr_words;
	int 	i;

	(void)env;
	i = 0;
	nbr_var = ft_count_raw_aoc(cmds) - 1;
	ft_bzero(buf, 9);
	ret = NULL;
	while (read(0, buf, 9))
	{
		ft_putchar(buf[0]);
		ret = ft_freejoin(ret, buf);
		if (BACK_SPACE)
		{
			// delete char;
		}
		if (ENTER)
			break ;
	}
	var_value = ft_strsplit(ret, ' ');
	nbr_words = count_words(ret, ' ');
	if (nbr_var == 1)
	{
		printf("Toto\n");
		create_last_var(cmds[1], var_value);
	}
	else if (nbr_var <= nbr_words)
	{
		while (i++ <= nbr_var)
		{
			if (i == nbr_var)
				create_last_var(cmds[i], &var_value[i - 1]);
			else
				create_var(cmds[i], var_value[i - 1]);
		}
	}
	return (0);
}
