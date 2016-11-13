/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/08 21:18:54 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void			set_possibilities(void)
{
	t_shell			*shell;
	char			*line;

	shell = recover_shell();
	line = get_last_word(list_to_string(), ' ');
	if (ft_strlen(line) == 0)
		return ;
	ft_lstdel(&(shell->posibilities), free_char);
	get_cmd_list(&(shell->posibilities), line);
	get_builtins_list(&(shell->posibilities), line);
	get_files_list(&(shell->posibilities), line);
	if (shell->posibilities && ft_lstcount(shell->posibilities) > 2)
	{
		ft_lst_bubble_sort(shell->posibilities, sort_by_lexycography);
		ft_lstremdup(&shell->posibilities, ft_lstremdup_str, free_char);
	}
}

static void			show_possibilities(void)
{
	t_shell			*shell;
	char			*line;
	int				len;
	char			*new_line;
	int				i;

	shell = recover_shell();
	line = get_last_word(list_to_string(), ' ');
	len = ft_strlen(line);
	free(line);
	if (shell->autocomplete_position >= ft_lstcount(shell->posibilities) - 1)
		return ;
	new_line = ft_strdup((char *)(ft_lstget_at(shell->posibilities,
		shell->autocomplete_position)->content));
	clean_last_x_char(len);
	i = 0;
	while (new_line[i])
	{
		inser_char(new_line[i]);
		i++;
	}
	free(new_line);
	shell->autocomplete_position = (shell->autocomplete_position <
		ft_lstcount(shell->posibilities)) ?
		shell->autocomplete_position + 1 : 1;
}

t_status			action_autocomplete(char *b)
{
	t_shell			*shell;
	char			*line;

	shell = recover_shell();
	line = list_to_string();
	if (!TAB || ft_strlen(line) == 0 || line[ft_strlen(line) - 1] == ' ')
	{
		free(line);
		return (TRYING);
	}
	free(line);
	if (shell->autocomplete_position == 0)
		set_possibilities();
	show_possibilities();
	return (READING);
}
