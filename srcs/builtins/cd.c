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

static void	print_err(char *str, char *path)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(path, 2);
}

static int	move_to(char *path)
{
	t_stat	path_stat;

	if (stat(path, &path_stat) == -1)
	{
		print_err("cd: No such file or directory: ", path);
		return (0);
	}
	else if (!S_ISDIR(path_stat.st_mode))
	{
		print_err("cd: Not a directory: ", path);
		return (0);
	}
	else if (chdir(path) != 0)
	{
		print_err("cd: Permission denied: ", path);
		return (0);
	}
	return (1);
}

static void	update_env_pwd(t_list **env, char *new_path, char *old_path)
{
	env_add_or_modify(env, "PWD", new_path);
	env_add_or_modify(env, "OLDPWD", old_path);
}

static int	cd_home_path(t_list **env, char *str)
{
	char		*tmp;
	char		*sub;

	sub = ft_strsub(str, 1, ft_strlen(str) - 1);
	tmp = ft_strjoin(env_get(*env, "HOME"), sub);
	if (move_to(tmp) == 0)
	{
		free(tmp);
		free(sub);
		return (1);
	}
	chdir(tmp);
	free(tmp);
	free(sub);
	return (0);
}

int			builtins_cd(t_list **env, char **cmds)
{
	char		old_path[1024];
	char		new_path[1024];
	int			i;

	i = 1;
	getcwd(old_path, 1024);
	if (!cmds[i] || ft_strcmp(cmds[i], "~") == 0)
		chdir(env_get(*env, "HOME"));
	else if (ft_strncmp(cmds[i], "~/", 2) == 0)
	{
		if (cd_home_path(env, cmds[i]))
			return (1);
	}
	else if (ft_strcmp(cmds[i], "..") == 0)
		chdir(cmds[i]);
	else if (ft_strcmp(cmds[i], "-") == 0)
		chdir(env_get(*env, "OLDPWD"));
	else
	{
		if (move_to(cmds[i]) == 0)
			return (1);
	}
	getcwd(new_path, 1024);
	update_env_pwd(env, old_path, new_path);
	return (0);
}
