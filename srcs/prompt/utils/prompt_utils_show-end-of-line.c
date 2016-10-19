/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils_show-end-of-line.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/19 15:48:23 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void    print_eol(void)
{
    t_shell		*shell;
	t_term		*term;
    int         index;
    void        *tmp;
    int         i;
    char        *string;

	shell = recover_shell();
	term = recover_term();
    index = shell->prompt->i_position;
    tputs(tgoto(LESTR, 0, 0), 0, ft_tputs);
    i = 0;
    string = (char *)malloc(sizeof(char) * (ft_lstcount(shell->prompt->line) - index));
    while (index + i < ft_lstcount(shell->prompt->line))
    {
        tmp = ft_lstget_at(shell->prompt->line, index + i)->content;
        string[i] = *(char*)tmp;
        i++;
    }
    write(term->tty, string, i);
    shell->prompt->i_position += i;
    while (i > 0)
    {
        utils_move_left();
        i--;
    }
    tputs(tgoto(RISTR, 0, 0), 0, ft_tputs);
}