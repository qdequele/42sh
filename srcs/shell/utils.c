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

static  int count_quote(char *cmd)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (cmd[i])
    {
        if (cmd[i] == '\'')
            j++;
        i++;
    }
    if (j % 4 != 0)
        return (j);
    else
        return (1);
}
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

        if (count_quote(cmd[i]) == 1)
        {
            while (cmd[i][0] == '\'')
            {
                cmd[i] = ft_strsub(cmd[i], 1, ft_strlen(cmd[i]) - 2);
            }
        }
        else if (count_quote(cmd[i]) > 2)
            cmd[i] = ft_strsub(cmd[i], 1, ft_strlen(cmd[i]) - 2);
        if (cmd[i][0] == '$')
        {
            tmp = cmd[i];
            if (cmd[i][1] == '?' && cmd[i][2] == '\0')
                cmd[i] = ft_itoa(shell->last_exit_code);
            else if (!cmd[i])
                cmd[i] = env_get(g_env, ft_strdup(&tmp[1]));
            else
                cmd[i] = env_get(g_vars, ft_strdup(&tmp[1]));
            printf("2--cmd[i] = %s\n", cmd[i]);
        }
        i++;
    }
    return (ft_array_to_string(cmd));
}