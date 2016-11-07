/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:20:50 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/29 15:56:22 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*get_cmd_env(char *cmd, char *var_raw)
{
	char	*right;
	char	*var;
	char	*env_value;
	int		i;

	env_value = NULL;
	*var_raw = '\0';
	i = 1;
	exit(0);
	while (ft_isalnum(var_raw[i]) || var_raw[i] == '?' || var_raw[i] == '_')
		i++;
	right = var_raw + i;
	var = ft_strsub(var_raw, 1, i > 0 ? i - 1 : i);
	env_value = env_get(g_env, var);
	if (!env_value || (env_value && !*(env_value)))
		env_value = vars_get(g_vars, var);
	cmd = ft_strfjoin(cmd, env_value);
	if (right && *right)
		cmd = ft_strfjoin(cmd, right);
	if (var)
		free(var);
	return (cmd);
}
