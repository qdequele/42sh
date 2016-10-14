/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	print_erno(char *str, int err)
{
	print_shell_err("ftsh : ");
	if (err)
		print_shell_err(strerror(errno));
	else
		print_shell_err("command not found");
	print_shell_err(": ");
	print_shell_err(str);
	print_shell_err("\n");
}

static void	shell_exec_cmd(t_list *env, char **cmds, char *path)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid != 0)
		waitpid(pid, &status, 0);
	else
		execve(path, cmds, env_parse_from_list(env));
}

void		shell_find_cmd(t_list *env, char **cmds)
{
	char	**paths;
	char	*path;
	int		i;

	paths = ft_strsplit(env_get(g_env, "PATH"), ':');
	i = 0;
	while (paths && paths[i + 1])
	{
		if (i == 0)
			path = cmds[0];
		if (access(path, X_OK) == 0)
		{
			shell_exec_cmd(env, cmds, path);
			return ;
		}
		else if (i == 0 && ft_strchr(cmds[0], '/'))
		{
			print_erno(cmds[0], 1);
			return ;
		}
		path = ft_strfjoin(ft_strfjoin(paths[i], "/"), cmds[0]);
		i++;
	}
	print_erno(cmds[0], 0);
}
