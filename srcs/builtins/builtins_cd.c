/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:32:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

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
	else if (chdir(ft_strdup(path)) != 0)
	{
		print_err("cd: Permission denied: ", path);
		return (0);
	}
	return (1);
}

int			builtins_cd(t_list **env, char **cmds)
{
	char		old_path[1024];
	char		new_path[1024];
	int			i;

	i = 1;
	getcwd(old_path, 1024);
	if (!cmds[i] || ft_strcmp(cmds[i], "~") == 0
		|| ft_strcmp(cmds[i], "~/") == 0)
		chdir(env_get(*env, "HOME"));
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
	env_add_or_modify(env, ft_strdup("PWD"), ft_strdup(new_path));
	env_add_or_modify(env, ft_strdup("OLDPWD"), ft_strdup(old_path));
	return (1);
}
