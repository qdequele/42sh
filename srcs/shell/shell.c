/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:27:47 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void		shell_core(t_list **env, char **cmds)
{
	if (cmds[0] && builtins_find(cmds[0]))
		builtins_exec(env, cmds);
	else if (cmds[0])
		shell_find_cmd(*env, cmds);
}


void		shell_exec_line(char *line)
{
	char	**cmds;
	char	**l_cmd;
	t_cmd 	*cmd;
	t_list	*env;
	int		i;

	env = g_env;
	i = 0;
	l_cmd = ft_strsplit(line, ';');
	while (l_cmd[i])
	{
		cmds = ft_str_to_tab(l_cmd[i]);
		if (cmds[0][0] == '!')
		{
			cmds[0] = action_seek_to_history(cmds[0]);
			if (cmds[0] == NULL)
				return ;
		}
		if ((cmd = parse_cmd(l_cmd[i])) && builtins_find(l_cmd[i]) == 0)
		{
			exec_cmd(cmd);
		}
		else
			shell_core(&env, cmds); //TODO : Starting here
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