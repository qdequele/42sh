/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_create_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 14:38:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char			*check_value(char opt, char *var_value)
{
	int		i;
	int		j;
	char	*new_value;

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

void	create_var(char *var_name, char *var_value, char opt)
{
	char	**set_env;

	set_env = (char**)malloc(sizeof(char*) * 3);
	set_env[0] = "setenv";
	set_env[1] = ft_strtrim(var_name);
	set_env[2] = check_value(opt, ft_strtrim(var_value));
	builtins_set(&g_env, set_env);
}

void	create_last_var(char *var_name, char **var_value, char opt)
{
	char	*last_var;
	int		i;

	i = 0;
	last_var = ft_strnew(1);
	if (ft_count_raw_aoc(var_value) > 1)
		last_var = ft_freejoin(last_var, "'");
	while (var_value[i])
	{
		if (i > 0)
			last_var = ft_freejoin(last_var, " ");
		if (!var_value[i + 1])
			var_value[i] = ft_strsub(var_value[i], 0,
				ft_strlen(var_value[i]) - 1);
		last_var = ft_freejoin(last_var, var_value[i]);
		i++;
	}
	if (ft_count_raw_aoc(var_value) > 1)
		last_var = ft_freejoin(last_var, "'");
	last_var = check_value(opt, last_var);
	create_var(var_name, last_var, opt);
}
