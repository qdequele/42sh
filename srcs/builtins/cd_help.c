/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 20:00:57 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		cd_error(int type, char *path)
{
	ft_putstr_fd("cd: ", 2);
	if (type == 0)
		ft_putstr_fd("An error occured\n", 2);
	else if (type == 1)
		ft_putstr_fd("too many arguments\n", 2);
	else if (type == 2)
		ft_putstr_fd("string not in pwd\n", 2);
	else if (type == 3)
		print_err(path, ": No such file or directory");
	else if (type == 4)
		print_err(path, ": Not a directory");
	else if (type == 5)
		print_err(path, ": Permission denied");
	return (1);
}

char	*cd_assert_home(void)
{
	int		fd;
	char	*logname;
	char	*line;

	logname = env_get(g_env, "LOGNAME");
	if (*env_get(g_env, "HOME") == '\0')
	{
		fd = open("/etc/passwd", O_RDONLY);
		if (fd < 0 || !*logname)
			return (NULL);
		while (ft_get_next_line(fd, &line))
		{
			if (ft_strncmp(logname, line, ft_strlen(logname)) == 0)
				return (ft_strrchr(line, ':') + 1);
		}
		close(fd);
		return (NULL);
	}
	return (env_get(g_env, "HOME"));
}

char	*cd_assert_multiple_args(char **cmds, t_options *options)
{
	char	cdpath[PATH_MAX];
	char	directory[PATH_MAX];

	if (cmds[options->start] && cmds[options->start + 1]
		&& cmds[options->start + 2])
	{
		cd_error(1, "");
		return (NULL);
	}
	getcwd(cdpath, PATH_MAX);
	if (!ft_strstr(cdpath, cmds[options->start]))
		cd_error(2, "");
	else
	{
		directory[0] = 0;
		ft_strncat(directory, cdpath, ft_strlen(cdpath) -
			ft_strlen(ft_strstr(cdpath, cmds[options->start])) - 1);
		ft_strcat(directory, "/");
		ft_strcat(directory, cmds[options->start + 1]);
		ft_strcat(directory, ft_strstr(cdpath, cmds[options->start]) +
			ft_strlen(cmds[options->start]));
		return (ft_strdup(directory));
	}
	return (NULL);
}

void	cd_update_path(char *old_path, char *path)
{
	env_add_or_modify(&g_env, "OLDPWD", old_path);
	env_add_or_modify(&g_env, "PWD", path);
}

int		cd_change_directory(char *curpath, int is_physical)
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
		cd_update_path(ft_strdup(old_path), curpath);
	else
		cd_update_path(ft_strdup(old_path), ft_strdup(new_path));
	return (0);
}
