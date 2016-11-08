/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/20 17:07:06 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static	char	*check_second_quote(char *str)
{
	char	*dst;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	dst = ft_strnew(1);
	while (str[i] != '\0')
	{
		if (str[i] != '"')
		{
			dst[j] = str[i];
			j++;
		}
		i++;
	}
	return (dst);
}

static	void	put_echo(char *str)
{
	int		i;

	i = 0;
	str = check_second_quote(str);
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
	int		i;
	int		j;

	(void)env;
	i = ft_count_raw_aoc(cmds);
	if (i <= 1)
		return (0);
	j = 1;
	if (ft_strcmp("-n", cmds[1]) == 0)
		j++;
	while (j < i)
	{
		put_echo(cmds[j]);
		ft_putchar(' ');
		j++;
	}
	if (ft_strcmp("-n", cmds[1]) != 0)
		ft_putchar('\n');
	return (0);
}
