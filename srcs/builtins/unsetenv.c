/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/31 11:43:20 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			builtins_unsetenv(t_list **env, char **cmds)
{
	t_list 	*tmp_env;
	int		i;

	tmp_env = *env;
	i = 1;
	while (cmds[i])
	{
		tmp_env = *env;
		if (ft_lst_seek(tmp_env, cmds[i]) == NULL)
		{
			ft_putstr_fd_c(RED, cmds[i], 2);
			ft_putstr_fd_c(RED, ": Wrong key.\n", 2);
		}
		else
			remove_key(env, cmds[i], &env_free_one);
		i++;
	}
	g_env = *env;
	return (0);
}
