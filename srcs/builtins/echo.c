/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/20 17:07:06 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static 		char *remove_backslash(char **cmds)
{
	char *ret;
	char *tmp;
	int i;
	int j;


	i= 0;
	j = 0;
	ret = ft_array_to_string(&cmds[1]);
	tmp =ft_strnew(ft_strlen(ret));
	while (ret[i] != '\0')
	{
		if (ret[i] != '\\' || (ret[i] == '\\' && ret[i + 1] == '\\'))
		{
			tmp[j] = ret[i];
			j++;

		}
		i++;
	}
	return (tmp);
}

int				builtins_echo(t_list **env, char **cmds)
{
	char 	*ret;
	int 	i;

	(void)env;
	i = 1;
	if (ft_strcmp("-n", cmds[1]) == 0)
	{
		ret = &*cmds[2];
		i = 2;
	}
	else
	{
		ret = remove_backslash(cmds);
	}
	ft_putstr_fd(ret, recover_term()->tty);
	if (i < 2)
	{
		ft_putchar_fd('\n', recover_term()->tty);
	}
	return (0);
}
