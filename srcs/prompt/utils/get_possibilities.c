/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possibilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/30 13:49:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void				get_cmd_list(t_list **possibilities, char *last_word)
{
	char			**paths;
	char			*tmp;
	char			*new_last_word;
	int				i;

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

void				get_builtins_list(t_list **possibilities, char *last_word)
{
	t_list			*list_new;
	t_builtin		*builtins;
	int				i;

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

void				get_files_list_one(t_list **possibilities, char *path,
	char *name, char *cmd_start)
{
	char			*file_to_access;
	char			*tmp;

	tmp = ft_strjoin("/", name);
	file_to_access = ft_strjoin(path, tmp);
	if (ft_strncmp(name, cmd_start, ft_strlen(cmd_start)) == 0
		&& access(file_to_access, X_OK) == 0)
		ft_lstaddend(possibilities, ft_lstnew(name,
			sizeof(char) * (ft_strlen(name) + 1)));
	free(file_to_access);
	free(name);
	free(tmp);
}

void				get_files_list(t_list **possibilities, char *last_word)
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
		get_files_list_one(possibilities, path,
			ft_strdup(pdirent->d_name), cmd_start);
	closedir(pdir);
	free(cmd_start);
	free(path);
}

void				reset_autocomplete_possibilities(void)
{
	t_shell			*shell;

	shell = recover_shell();
	shell->autocomplete_position = 0;
	ft_lstdel(&(shell->posibilities), free_char);
}
