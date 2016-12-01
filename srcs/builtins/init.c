/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/31 18:40:01 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_builtin	*builtins_init(void)
{
	static t_builtin	f[] = {
		{"cd", builtins_cd},
		{"env", builtins_env},
		{"setenv", builtins_setenv},
		{"unsetenv", builtins_unsetenv},
		{"export", builtins_export},
		{"unset", builtins_unset},
		{"set", builtins_set},
		{"exit", builtins_exit},
		{"history", builtins_history},
		{"echo", builtins_echo},
		{"read", builtins_read},
		{"readonly", builtins_readonly},
		{"unreadonly", builtins_unreadonly},
		{"jobs", builtins_jobs},
		{"bg", builtins_bg},
		{"fg", builtins_fg},
		{"help", builtins_help},
		{NULL, NULL}
	};

	return ((void *)f);
}

int			builtins_find(char *cmd)
{
	t_builtin	*builtins;
	int			i;

	i = 0;
	builtins = builtins_init();
	if (ft_match(cmd, "*=*") == 1)
		return (1);
	while (builtins[i].name)
	{
		if (ft_strcmp(builtins[i].name, cmd) == 0)
			return (1);
		i++;
	}
	return (0);
}

int			builtins_exec(t_list **env, char **cmds)
{
	t_builtin	*builtins;
	int			i;

	i = 0;
	builtins = builtins_init();
	if (ft_match(cmds[i], "*=*") == 1)
		return (builtins_set_equal(env, cmds));
	while (builtins[i].name)
	{
		if (ft_strcmp(builtins[i].name, cmds[0]) == 0)
			return (builtins[i].f(env, cmds));
		i++;
	}
	return (1);
}
