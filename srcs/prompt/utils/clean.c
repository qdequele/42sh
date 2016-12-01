/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/11/18 22:25:23 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void		clean_prompt(void)
{
	t_shell	*shell;
	int		i;
	int		j;

	shell = recover_shell();
	j = 0;
	i = ft_lstcount(shell->prompt->line) + 1;
	utils_move_start();
	while (++j <= i)
		ft_tputs(' ');
	while (--j > 0)
		tputs(tgoto(LESTR, 0, 0), 0, ft_tputs);
}

void		clean_last_x_char(int i)
{
	t_shell	*shell;

	shell = recover_shell();
	while (shell->prompt->i_pos < ft_lstcount(shell->prompt->line))
	{
		utils_move_right();
	}
	while (shell->prompt->i_pos > 0 && i > 0)
	{
		delete_one_char();
		tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
		utils_move_left();
		i--;
	}
	delete_one_char();
	tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
}

void		free_char(void *content, size_t size)
{
	UNUSED(size);
	if (content)
		free(content);
}

void		free_input(void)
{
	t_shell	*shell;

	shell = recover_shell();
	ft_lstdel(&(shell->prompt->line), &free_char);
	free_copy();
}

int			sort_by_lexycography(t_list *node)
{
	t_list	*n_elem;

	n_elem = node->next;
	if (n_elem && node->content &&
		(ft_strlen((char *)(node->content)) >
		ft_strlen((char *)(n_elem->content))) > 0)
		return (1);
	return (0);
}
