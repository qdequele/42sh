/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 19:12:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_status	action_insert_char(char *b)
{
	if (TAB)
	{
		inser_char(' ');
		inser_char(' ');
		inser_char(' ');
		inser_char(' ');
	}
	else
	{
		if (b[0] && ft_isprint(b[0]))
			inser_char(b[0]);
		if (b[1] && ft_isprint(b[1]))
			inser_char(b[1]);
		if (b[2] && ft_isprint(b[2]))
			inser_char(b[2]);
		if (b[3] && ft_isprint(b[3]))
			inser_char(b[3]);
	}
	return (READING);
}

t_status	action_delete_char(char *b)
{
	if (!BACK_SPACE)
		return (TRYING);
	erase_one_char();
	return (READING);
}

t_status	action_delete_next_char(char *b)
{
	if (!DEL)
		return (TRYING);
	delete_one_char();
	return (READING);
}
