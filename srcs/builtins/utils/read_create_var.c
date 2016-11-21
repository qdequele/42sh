/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_create_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/08 22:33:22 by qdequele         ###   ########.fr       */
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
	if (ft_strlen(var_value) == 0)
		return (ft_strdup(""));
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
	return (new_value);
}

void		create_last_var(char *var_name, char **var_value, char opt)
{
	char	*last_var;
	char	*new_val;
	char	*tmp;
	int		i;

	i = -1;
	if (!var_value)
		return (vars_add_or_modify(&g_l_vars, var_name, ""));
	last_var = (char*)malloc(sizeof(char));
	while (var_value[++i])
	{
		if (i > 0)
			last_var = ft_strfjoin(last_var, " ");
		if (!var_value[i + 1] && ft_strlen(var_value[i]) > 0)
			var_value[i][ft_strlen(var_value[i]) - 1] = '\0';
		last_var = ft_strfjoin(last_var, var_value[i]);
	}
	tmp = check_value(opt, last_var);
	free(last_var);
	last_var = ft_strtrim(tmp);
	free(tmp);
	new_val = check_value(opt, last_var);
	vars_add_or_modify(&g_l_vars, last_var, new_val);
	free(last_var);
	free(new_val);
}
