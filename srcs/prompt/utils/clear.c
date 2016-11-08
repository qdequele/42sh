/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/30 13:50:35 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	clean_prompt(void)
{
	t_shell	*shell;
	int		i;

	shell = recover_shell();
	if (!shell->prompt->str_cpy)
		i = 0;
	else
		i = ft_strlen(shell->prompt->str_cpy);
	while (shell->prompt->i_position < ft_lstcount(shell->prompt->line) - i)
	{
		utils_move_right();
	}
	while (shell->prompt->i_position > 0)
	{
		tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
		utils_move_left();
	}
	tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
}

void	clean_last_x_char(int i)
{
	t_shell	*shell;

	shell = recover_shell();
	while (shell->prompt->i_position < ft_lstcount(shell->prompt->line))
	{
		utils_move_right();
	}
	while (shell->prompt->i_position > 0 && i > 0)
	{
		delete_one_char();
		tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
		utils_move_left();
		i--;
	}
	delete_one_char();
	tputs(tgoto(DCSTR, 0, 0), 0, ft_tputs);
}

void	free_char(void *content, size_t size)
{
	UNUSED(size);
	if (content)
		free(content);
}

int		sort_by_lexycography(t_list *node)
{
	t_list	*n_elem;

	n_elem = node->next;
	if (n_elem && (ft_strlen((char *)(node->content)) >
		ft_strlen((char *)(n_elem->content))) > 0)
		return (1);
	return (0);
}
