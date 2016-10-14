/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

t_status	action_exec_cmd(char *buf)
{
	if (!ENTER || buf != NULL)
		return (TRYING);
	ft_putchar('\n');
	return (FOUND);
}

t_status	action_ignore_input(char *buf)
{
	if (!IGNORE_1 || buf != NULL)
		return (TRYING);
	return (READING);
}

t_status	action_shell_quit(char *buf)
{
	if (!QUIT || buf != NULL)
		return (TRYING);
	return (READING);
}