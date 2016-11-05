/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/30 13:49:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	erase_one_char(void)
{
	t_shell	*shell;

	shell = recover_shell();
	ft_console("i_position : %d, count : %d\n", shell->prompt->i_position, ft_lstcount(shell->prompt->line));
	if(shell->prompt->i_position <= ft_lstcount(shell->prompt->line)
		&& shell->prompt->i_position > 0)
	{
		tputs(tgoto(LESTR, 0, 0), 1, ft_tputs);// move left
		tputs(DMSTR, 1, ft_tputs);// enter in delete mode
		tputs(DCSTR, 1, ft_tputs);// delete char
		tputs(EDSTR, 1, ft_tputs);// exit delete mode
		shell->prompt->i_position--;
		ft_lstdel_at(&shell->prompt->line, shell->prompt->i_position, free_char);
	}
}

void erase_x_chars(int x)
{
    int i;

    i = 0;
    while(i < x)
    {
        erase_one_char();
        i++;
    }
}

void    delete_one_char(void)
{
	t_shell	*shell;

	shell = recover_shell();
	if(shell->prompt->i_position < ft_lstcount(shell->prompt->line)
		&& shell->prompt->i_position >= 0)
	{
		tputs(DMSTR, 1, ft_tputs);// enter in delete mode
		tputs(DCSTR, 1, ft_tputs);// delete char
		tputs(EDSTR, 1, ft_tputs);// exit delete mode
		ft_lstdel_at(&shell->prompt->line, shell->prompt->i_position, free_char);
	}
}

void delete_x_chars(int x)
{
	int i;

	i = 0;
	while(i < x)
	{
		delete_one_char();
		i++;
	}
}
