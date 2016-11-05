/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 11:48:56 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	print_shell_err(char *s)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\e[0m", 2);
}

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

	reset_major_signals();
	if ((pid = fork()) == 0)
		execve(path, cmds, env_parse_from_list(env));
	else
		waitpid(pid, 0, 0);
	ignore_major_signals();
	return (0);
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

int		shell_core(t_list **env, char **cmds)
{
	if (cmds[0] && builtins_find(cmds[0]))
		return (builtins_exec(env, cmds));
	else if (cmds[0])
	{
		return (shell_find_cmd(*env, cmds));
	}
	else
		return (1);
}