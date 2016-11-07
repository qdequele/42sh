/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/07 19:06:36 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	get_cmd_list(t_list **possibilities, char *last_word)
{
	char		**paths;
	char		*tmp;
	char		*new_last_word;
	int			i;

	paths = ft_strsplit(env_get(g_env, "PATH"), ':');
	i = 0;
	while (paths && paths[i] && paths[i][0])
	{
		tmp = ft_strjoin("/", last_word);
		new_last_word = ft_strjoin(paths[i], tmp);
		get_files_list(possibilities, new_last_word);
		free(tmp);
		i++;
	}
	ft_free_aoc(paths);
}

void	get_builtins_list(t_list **possibilities, char *last_word)
{
	t_list		*list_new;
	t_builtin	*builtins;
	int			i;

	i = 0;
	builtins = builtins_init();
	while (builtins[i].name)
	{
		if (ft_strncmp(builtins[i].name, last_word, ft_strlen(last_word)) == 0)
		{
			if ((list_new = ft_lstnew(builtins[i].name,
				sizeof(char) * ft_strlen(builtins[i].name))))
				ft_lstaddend(possibilities, list_new);
		}
		i++;
	}
}

void 	get_files_list_one(t_list **possibilities, char *path, char *name, char *cmd_start)
{
	char *file_to_access;
	char *tmp;

	tmp = ft_strjoin("/", name);

	file_to_access = ft_strjoin(path, tmp);

	if (ft_strncmp(name, cmd_start, ft_strlen(cmd_start)) == 0
		&& access(file_to_access, X_OK) == 0)
	{
		ft_lstaddend(possibilities, ft_lstnew(name, sizeof(char) * (ft_strlen(name) + 1)));
	}
	free(file_to_access);
	free(name);
	free(tmp);
}

void	get_files_list(t_list **possibilities, char *last_word)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	char			*path;
	char			*cmd_start;
	struct stat		sb;

	path = before_last_word(last_word, '/');
	cmd_start = get_last_word(last_word, '/');
	if (((pdir = opendir(path)) == NULL) || stat(path, &sb) ||
		!((S_ISREG(sb.st_mode) || S_ISDIR(sb.st_mode))))
	{
		free(cmd_start);
		free(path);
		return ;
	}
	while (((pdirent = readdir(pdir)) != NULL))
		get_files_list_one(possibilities, path, ft_strdup(pdirent->d_name), cmd_start);
	closedir(pdir);
	free(cmd_start);
	free(path);
}

static void set_possibilities(void)
{
	t_shell	*shell;
	char	*line;


	shell = recover_shell();
	line = get_last_word(list_to_string(), ' ');
	if (ft_strlen(line) == 0)
		return ;
	ft_lstdel(&(shell->posibilities), free_char);
	get_cmd_list(&(shell->posibilities), line);
	get_builtins_list(&(shell->posibilities), line);
	get_files_list(&(shell->posibilities), line);
	ft_lst_bubble_sort(shell->posibilities, sort_by_lexycography);
	ft_lstremdup(&shell->posibilities, ft_lstremdup_str, free_char);
}

static void show_possibilities(void)
{
	t_shell	*shell;
	char	*line;
	int		len;
	char	*new_line;
	int		i;

	shell = recover_shell();
	line = get_last_word(list_to_string(), ' ');
	len = ft_strlen(line);
	free(line);
	if (shell->autocomplete_position >= ft_lstcount(shell->posibilities))
		return ;
	new_line = ft_strdup((char *)(ft_lstget_at(shell->posibilities, shell->autocomplete_position)->content));
	clean_last_x_char(len);
	i = 0;
	while (new_line[i])
	{
		inser_char(new_line[i]);
		i++;
	}
	free(new_line);
	if (shell->autocomplete_position < ft_lstcount(shell->posibilities))
		shell->autocomplete_position++;
	else
		shell->autocomplete_position = 1;
}

t_status	action_autocomplete(char *buf)
{
	t_shell	*shell;
	char	*line;

	shell = recover_shell();
	line = list_to_string();
	if (!TAB || ft_strlen(line) == 0 || line[ft_strlen(line) - 1] == ' ')
	{
		free(line);
		return (TRYING);
	}
	if (shell->autocomplete_position == 0)
	{
		set_possibilities();
	}
	show_possibilities();
	free(line);
	return (READING);
}
