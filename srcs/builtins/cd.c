/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 20:00:57 by qdequele         ###   ########.fr       */
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

int				cd_change_directory(char *curpath, int is_physical)
{
	t_stat		stat_;
	char		old_path[PATH_MAX];
	char		new_path[PATH_MAX];

	getcwd(old_path, 256);
	if (stat(curpath, &stat_) == -1)
		return (cd_error(3, curpath));
	if (!S_ISDIR(stat_.st_mode))
		return (cd_error(4, curpath));
	if (chdir(curpath) != 0)
		return (cd_error(5, curpath));
	getcwd(new_path, 256);
	if (is_physical && stat(curpath, &stat_) == 0 && !S_ISLNK(stat_.st_mode))
		cd_update_path(old_path, curpath);
	else
		cd_update_path(old_path, new_path);
	free(curpath);
	return (0);
}

int				builtins_cd(t_list **env, char **cmds)
{
	t_options	options;
	char		*d;

	UNUSED(env);
	options = t_options_parser(cmds, "LP");
	if (!cmds[options.start] && ft_strcmp(cmds[options.start - 1], "-") == 0)
		options.start--;
	d = (cmds[options.start]) ? ft_strdup(cmds[options.start]) : ft_strdup("");
	if (!cmds[options.start] || ft_strncmp(d, "~", 1) == 0)
		d = cd_assert_home(d);
	if (!d)
		return (cd_error(0, ft_strdup("")));
	if (cmds[options.start] && ft_strcmp(cmds[options.start], "-") == 0)
	{
		free(d);
		d = ft_strdup(env_get(g_env, "OLDPWD"));
	}
	if (cmds[options.start] && cmds[options.start + 1])
	{
		free(d);
		d = cd_assert_multiple_args(cmds, &options);
		if (!d)
			return (1);
	}
	return (cd_move_path(&options, d));
}
