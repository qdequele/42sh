/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_create_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/08 22:33:22 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char		*check_value(char opt, char *var_value)
{
	int		i;
	int		j;
	char	*new_value;

	i = 0;
	j = 0;
	new_value = ft_strnew(ft_strlen(var_value));
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
	new_value[i] = '\0';
	free(var_value);
	return (new_value);
}

void		create_last_var(char *var_name, char **var_value, char opt)
{
	char	*last_var;
	char	*new_val;
	int		i;

	i = 0;
	last_var = ft_strnew(1);
	while (var_value[i])
	{
		if (i > 0)
			last_var = ft_freejoin(last_var, " ");
		if (!var_value[i + 1] && ft_strlen(var_value[i]) > 0)
			var_value[i][ft_strlen(var_value[i]) - 1] = '\0';
		last_var = ft_freejoin(last_var, var_value[i]);
		i++;
	}
	last_var = check_value(opt, last_var);
	new_val = check_value(opt, ft_strtrim(last_var));
	free(last_var);
	last_var = ft_strtrim(var_name);
	vars_add_or_modify(&g_vars, last_var, new_val);
	free(last_var);
	free(new_val);
}
