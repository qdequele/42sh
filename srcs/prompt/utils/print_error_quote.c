/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 18:52:25 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		print_error(char flag)
{
	t_prompt	*prompt;

	prompt = recover_shell()->prompt;
	if (flag)
		ft_putchar_c(GREEN, flag);
	ft_putstr_c(GREEN, "quote> ");
	prompt->p_pos = prompt->i_pos;
	return (0);
}
