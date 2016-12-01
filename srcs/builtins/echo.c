/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/08 22:06:25 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	void	put_echo(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			i += 2;
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

int				builtins_echo(t_list **env, char **cmds)
{
	int			i;
	int			j;

	UNUSED(env);
	i = ft_count_raw_aoc(cmds);
	if (i <= 1)
	{
		ft_putchar('\n');
		return (0);
	}
	j = 1;
	if (ft_strcmp("-n", cmds[1]) == 0)
		j++;
	while (j < i)
	{
		put_echo(cmds[j]);
		if (j < i - 1)
			ft_putchar(' ');
		j++;
	}
	if (ft_strcmp("-n", cmds[1]) != 0)
		ft_putchar('\n');
	else
		ft_putchar_fd('\n', 2);
	return (0);
}
