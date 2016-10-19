/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:31:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_cmd	*build_exec(char *str)
{
	t_exec	*exec;
	char	**cmd;

	exec = (t_exec*)malloc(sizeof(t_exec));
	exec->type = EXEC;
	cmd = ft_str_to_tab(str);
	exec->cmd = cmd[0];
	exec->opt = cmd;
	return ((t_cmd*)exec);
}


t_cmd 	*parse_cmd(char *cmd)
{
	size_t		i;

	i = 0;
	while (i < (ft_strlen(cmd)) && cmd[i] != '|')
		i++;
	if (ft_strchr(cmd, '|'))
		return (parse_pipe(cmd));
	else
		return (build_exec(cmd));
}

void	exec_cmd(t_cmd *cmd)
{
	t_pipe	*pipe;
	t_exec	*exec;

	if (cmd->type == PIPE)
	{
		pipe = (t_pipe*)cmd;
		exec_pipe(cmd);
	}
	else if (cmd->type == EXEC)
	{
		exec = (t_exec*)cmd;
		shell_find_cmd(g_env, exec->opt);
	}
}