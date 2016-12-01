/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:20:50 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:23:43 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*get_cmd_env(char *cmd, char *var_raw)
{
	char	*right;
	char	*var;
	char	*env_value;
	int		i;
	int		len;

	len = ft_strlen(var_raw);
	env_value = NULL;
	*var_raw = '\0';
	i = 1;
	while (ft_isalnum(var_raw[i]) || var_raw[i] == '?' || var_raw[i] == '_')
		i++;
	right = (i < len) ? var_raw + i : NULL;
	var = ft_strsub(var_raw, 1, i > 0 ? i - 1 : i);
	env_value = env_get(g_env, var);
	if (!env_value || (env_value && !*(env_value)))
		env_value = vars_get(g_l_vars, var);
	cmd = ft_strfjoin(cmd, env_value);
	if (right && *right)
		cmd = ft_strfjoin(cmd, right);
	if (var)
		free(var);
	return (cmd);
}
