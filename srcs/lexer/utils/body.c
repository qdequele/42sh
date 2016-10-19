/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_body                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:31:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*body_left(char *cmd, char c)
{
	int 	i;

	i = 0;
	while (cmd[i] != c && cmd[i] != '\0')
		i++;
	cmd = ft_strsub(cmd, 0, i - 1);
	ft_strtrim(cmd);
	return (cmd);
}

char 	*body_right(char *cmd, char c)
{
	int 	i;

	i = 0;
	while (cmd[i] != c && cmd[i] != '\0')
		i++;
	i++;
	if (c == '<')
		i += 2;
	cmd = ft_strsub(cmd, i, ft_strlen(cmd) - i);
	ft_strtrim(cmd);
	return (cmd);
}
