/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 20:00:57 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int		cd_move_path(t_options *options, char *curpath)
{
	if (ft_is_in(options->options, 'P') && !ft_is_in(options->options, 'L'))
	{
		if (*curpath == '/')
			curpath = ft_strfjoin(ft_strjoin(env_get(g_env, "PWD"), "/"),
				curpath);
		return (cd_change_directory(curpath, 1));
	}
	else
		return (cd_change_directory(curpath, 0));
}

int				builtins_cd(t_list **env, char **cmds)
{
	t_options	options;
	char		*directory;
	char		*curpath;

	UNUSED(env);
	options = t_options_parser(cmds, "LP");
	if (!cmds[options.start] && ft_strcmp(cmds[options.start - 1], "-") == 0)
		options.start--;
	directory = cmds[options.start];
	if (!directory || ft_strcmp(cmds[options.start], "~") == 0)
		directory = cd_assert_home();
	if (!directory)
		return (cd_error(0, ""));
	if (cmds[options.start] && ft_strcmp(cmds[options.start], "-") == 0)
		directory = env_get(g_env, "OLDPWD");
	if (cmds[options.start] && cmds[options.start + 1])
	{
		directory = cd_assert_multiple_args(cmds, &options);
		if (!directory)
			return (1);
	}
	curpath = directory;
	return (cd_move_path(&options, curpath));
}
