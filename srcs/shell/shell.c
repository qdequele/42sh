/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/21 13:09:14 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		shell_core(t_list **env, char **cmds)
{
	if (cmds[0] && builtins_find(cmds[0]))
		return(builtins_exec(env, cmds));
	else if (cmds[0])
		return(shell_find_cmd(*env, cmds));
}


int		shell_exec_line(char *cmd)
{
	t_cmd 	*cmd;
	t_list	*env;
	char	**cmds;

	env = g_env;
	cmds = ft_str_to_tab(cmd);
	if (cmds[0][0] == '!')
	{
		cmds[0] = action_seek_to_history(cmds[0]);
		if (cmds[0] == NULL)
			return (0);
	}
	if ((cmd = parse_cmd(cmd)) && builtins_find(cmd) == 0)
		return (exec_cmd(cmd));
	else
		return (shell_core(&env, cmds));
}

int 		shell_parse_or_line(char *cmd)
{

}

int 		shell_parse_and_line(char *cmd)
{

}

int 		shell_parse_semicolon_line(char *line)
{
	char	**l_cmd;
	int		i;

	i = 0;
	l_cmd = ft_strsplit(line, ';');
	while (l_cmd[i])
	{
		shell_exec_line(cmds, l_cmd[i]);
		i++;
	}
}

void	shell_get_lines(void)
{
	t_shell	*shell;
	char	*line;

	shell = recover_shell();
	init_shell();
	while (1)
	{
		print_shell();
		shell->history_position = 0;
		line = prompt_create_line();
		ft_lstadd(&shell->history,
			ft_lstnew(line, sizeof(char) * ft_strlen(line)));
		shell_exec_line(line);
	}
	return ;
}