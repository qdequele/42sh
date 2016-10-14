/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/09 17:23:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static	void	ft_put_echo(char *str)
{
	int i;

	i = 0;
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		str = ft_strsub(str, 1, ft_strlen(str) - 2);
	while(str[i] != '\0')
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

int		builtins_echo(t_list **env, char **cmds)
{
	int i;
	int j;

	(void)env;
	i = ft_count_raw_aoc(cmds);
	j = 1;
	if (ft_strcmp("-n", cmds[1]) == 0)
		j++;
	while (j < i)
	{
		ft_put_echo(cmds[j]);
		ft_putchar(' ');
		j++;
	}
	if (ft_strcmp("-n", cmds[1]) != 0)
		ft_putchar('\n');
	return (1);
}
