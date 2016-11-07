/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static int	print_erno(char *str, int err)
{
	if (str[0] == '!')
		str = list_to_string();
	print_shell_err("42sh : ");
	if (err)
		print_shell_err(strerror(errno));
	else
		print_shell_err("command not found");
	print_shell_err(": ");
	print_shell_err(str);
	print_shell_err("\n");
	return (1);
}

static int	shell_exec_cmd(t_list *env, char **cmds, char *path)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid != 0)
		waitpid(pid, &status, 0);
	else
		execve(path, cmds, env_parse_from_list(env));
	return (status);
}

int			shell_find_cmd(t_list *env, char **cmds)
{
	char		**paths;
	char		*path;
	int			i;
	struct stat	sb;

	paths = ft_strsplit(env_get(g_env, "PATH"), ':');
	i = 0;
	while (paths && paths[i + 1])
	{
		if (i == 0)
			path = cmds[0];
		if (access(path, X_OK) == 0 && !stat(path, &sb))
		{
			if (S_ISREG(sb.st_mode) && sb.st_mode & 0111)
				return (shell_exec_cmd(env, cmds, path));
		}
		else if (i == 0 && ft_strchr(cmds[0], '/'))
		{
			return (print_erno(cmds[0], 1));
		}
		path = ft_strfjoin(ft_strfjoin(paths[i], "/"), cmds[0]);
		i++;
	}
	return (print_erno(cmds[0], 0));
}
