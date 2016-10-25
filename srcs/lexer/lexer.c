/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 17:31:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_cmd 	*parse_cmd(char *cmd)
{
	size_t		i;
	char 		*p_heredoc;

	i = 0;
	p_heredoc = NULL;
	while (i < (ft_strlen(cmd)) && cmd[i] != '|' && cmd[i] != '<')
		i++;
	if (ft_strchr(cmd, '|'))
		return (parse_pipe(cmd));
	if ((p_heredoc = ft_strchr(cmd, '<')) && p_heredoc[1] == '<')
	{	
		return (parse_heredoc(cmd));
	}
	else if (ft_strchr(cmd, '>'))
	 	return (parse_redirection(cmd));
	else
		return (build_exec(cmd));
}   