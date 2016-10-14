/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42shell.h>

void	ft_clean_prompt(void)
{
	t_shell		*shell;
	t_prompt	*prompt;

	shell = recover_shell();
	prompt = shell->prompt;
	prompt->l_lenght = ft_lstcount(prompt->line);
	while (prompt->x < prompt->l_lenght)
		ft_arrow_right();
	while (prompt->i_position > 0)
	{
		ft_arrow_left();
		tputs(tgoto((tgetstr("dc", NULL)), 0, 0), 0, tputs_putchar);
	}
}