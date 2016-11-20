/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_history_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/09 14:12:23 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	print_error_history(int i, char *cmds)
{
	if (i == 0)
		print_err("42sh : no such event: ", cmds);
	else
	{
		ft_putstr_fd("42sh : no such event: ", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("\n", 2);
	}
}
