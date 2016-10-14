/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/12 16:15:54 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

static t_builtin	*builtins_init(void)
{
	static t_builtin	f[] = {
		{"cd", builtins_cd},
		{"env", builtins_env},
		{"setenv", builtins_setenv},
		{"unsetenv", builtins_unsetenv},
		{"exit", builtins_exit},
		{"history", builtins_history},
		{"echo", builtins_echo},
		{NULL, NULL}
	};
	return ((void *)f);
}

int					builtins_find(char *cmd)
{
	t_builtin	*builtins;
	int			i;

	i = 0;
	builtins = builtins_init();
	while (builtins[i].name)
	{
		if (ft_strcmp(builtins[i].name, cmd) == 0)
			return (1);
		i++;
	}
	return (0);
}

int					builtins_exec(t_list **env, char **cmds)
{
	t_builtin	*builtins;
	int			i;

	i = 0;
	builtins = builtins_init();
	while (builtins[i].name)
	{
		if (ft_strcmp(builtins[i].name, cmds[0]) == 0)
			return (builtins[i].f(env, cmds));
		i++;
	}
	return (0);
}
