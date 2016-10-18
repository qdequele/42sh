/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_actions_autocomplete.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/18 17:24:06 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static t_builtin	*builtins_init(void)
{
	static t_builtin	f[] = {
		{"cd", builtins_cd},
		{"env", builtins_env},
		{"setenv", builtins_setenv},
		{"unsetenv", builtins_unsetenv},
		{"exit", builtins_exit},
		{"history", builtins_history},
		{"echo", builtins_echo},
		{NULL, NULL}
	};
	return ((void *)f);
}

void ft_print_lst(t_list *lst)
{
	t_term *term;

	term = recover_term();
	// ft_putnbr(term->wins.ws_col);
	// ft_putnbr(term->wins.ws_row);
	while (lst)
	{
		//ft_putendl((char *)lst->content);
		lst = lst->next;
	}
}

static int	ft_open_folder_path(char *path, t_list **list_bin)
{
	DIR 			*dir;
	struct	dirent	*dir_struct;
	char			*name_bin;

	if ((dir = opendir(path)) == NULL)
		return (0);
	while ((dir_struct = readdir(dir)) != NULL)
	{
		if (dir_struct->d_name[0] != '.')
		{
			name_bin = ft_strdup(dir_struct->d_name);
			ft_lstaddend(list_bin, ft_lstnew(name_bin, sizeof(ft_strlen(name_bin))));
			ft_strdel(&name_bin);
		}
	}
	return (1);
}

static void stock_cmd_binaire(t_shell *shell, t_list **list_bin)
{
	t_list		*env;
	char		*name_bin;
	char		**tab_bin;
	int			i;

	(void)shell;
	i = 0;
	(void)shell;
	name_bin = NULL;
	env = g_env;
	tab_bin = ft_strsplit(env_get(env, "PATH"), ':');
	while (tab_bin[i])
	{

		ft_open_folder_path(tab_bin[i], list_bin);
		ft_strdel(&tab_bin[i]);
		i++;
	}
}

static void stock_cmd_builtins(t_list **list_bin)
{
	t_builtin	*builtins;
	char		*name_bin;
	int			i;

	i = 0;
	name_bin = NULL;
	builtins = builtins_init();
	while (builtins[i].name)
	{
		name_bin = ft_strdup(builtins[i].name);
		ft_lstaddend(list_bin, ft_lstnew(name_bin, sizeof(ft_strlen(name_bin))));
		ft_strdel(&name_bin);
		i++;
	}
}

t_status	action_autocomplete(char *buf)
{
	t_shell	*shell;
	t_list	*list_bin;
	char	*line;

	list_bin = NULL;
	if (!TAB)
		return (TRYING);
	shell = recover_shell();
	line = list_to_string();
	stock_cmd_builtins(&list_bin);
	stock_cmd_binaire(shell, &list_bin);
	ft_print_lst(list_bin);
	return (READING);
}
