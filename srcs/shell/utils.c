/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/26 13:08:03 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char    *replace_vars(char *line)
{
    char    **cmd;
    char    *tmp;
    int     i;
    t_shell	*shell;

    i = 0;
    cmd = ft_strsplit(line, ' ');
    shell = recover_shell();
    while(cmd[i])
    {
        tmp = cmd[i];
        if (cmd[i][0] == '$')
        {
            if (cmd[i][1] == '?' && cmd[i][2] == '\0')
                cmd[i] = ft_itoa(shell->last_exit_code);
            else if (!cmd[i])
                cmd[i] = env_get(g_env, ft_strdup(&tmp[1]));
            else
                cmd[i] = env_get(g_vars, ft_strdup(&tmp[1]));
        }
        i++;
    }
    return (ft_array_to_string(cmd));
}