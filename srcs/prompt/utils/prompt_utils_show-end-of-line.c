/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils_show-end-of-line.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/24 13:51:44 by qdequele         ###   ########.fr       */
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
    ft_console_log("index before : ");
    ft_console_log_num(index);
    ft_console_log("\n");
    i = 0;
    string = (char *)malloc(sizeof(char) * (ft_lstcount(shell->prompt->line) - index + 1));
    while (index + i < ft_lstcount(shell->prompt->line))
    {
        tmp = ft_lstget_at(shell->prompt->line, index + i)->content;
        string[i] = *(char*)tmp;
        i++;
    }
    string[i] = '\0';
    ft_console_log("string to write : ");
    ft_console_log(string);
    ft_console_log("\n");
    write(term->tty, ft_strdup(string), i);
    shell->prompt->i_position += i;
    while (i > 0)
    {
        utils_move_left();
        i--;
    }
}