/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 19:12:58 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

// static void show_list(t_list *elem)
// {
// 	ft_console("--- line : %s\n", (char *)(elem->content));
// }

/*
** public
** DESCRIPTION  : Liste les commandes unix qui commencent par le denier mot de la ligne entrée par l'utilisateur
** EXPLICATIONS : Il faut aller chercher les executables qui se trouve dans les chemins contenue dans la variable d'env PATH
*/
void 	get_cmd_list(t_list **possibilities, char *last_word)
{
	char		**paths;
	int			i;

	paths = ft_strsplit(env_get(g_env, "PATH"), ':');
	i = 0;
	while (paths && paths[i] && paths[i][0])
	{
		get_files_list(possibilities, ft_strjoin(paths[i], ft_strjoin("/", last_word)));
		i++;
	}
	ft_free_aoc(paths);
}

/*
** public
** DESCRIPTION  : Liste les builtins qui commencent par le denier mot de la ligne entrée par l'utilisateur
** EXPLICATIONS : Ici les builtins sont fait maison donc on peut les retrouver grace à la commande builtins_init 
*/
void 	get_builtins_list(t_list **possibilities, char *last_word)
{
	t_list 		*list_new;
	t_builtin	*builtins;
	int			i;

	i = 0;
	builtins = builtins_init();
	while (builtins[i].name)
	{
		if (ft_strncmp(builtins[i].name, last_word, ft_strlen(last_word)) == 0)
		{
			list_new = ft_lstnew(builtins[i].name, sizeof(char) * ft_strlen(builtins[i].name));
			if (list_new)
				ft_lstaddend(possibilities, list_new);
		}
		i++;
	}
}

/*
** public
** DESCRIPTION  : Liste les fichier et les dossiers contenue dans le path passé en parametre
** EXPLICATIONS : Dans le paramètre last_word, on retrouve le path (ce qui est avant le denier /) et le debut de la commande (ce qui est apprès le dernier /) 
*/
void 	get_files_list(t_list **possibilities, char *last_word)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	char 			*path;
	char 			*cmd_start;
	t_list 			*list_new;
	char 			*name;
	struct stat		sb;

	path = before_last_word(last_word, '/');
	cmd_start = get_last_word(last_word, '/');
	pdir = opendir(path);
	if (pdir != NULL)
	{
		while (((pdirent = readdir(pdir)) != NULL))
		{
			name = ft_strdup(pdirent->d_name);
			if (ft_strncmp(name, cmd_start, ft_strlen(cmd_start)) == 0
				&& access(ft_strjoin(path, ft_strjoin("/", name)), X_OK) == 0
				&&!stat(path, &sb) && (S_ISREG(sb.st_mode) || S_ISDIR(sb.st_mode)))
			{
				list_new = ft_lstnew(name, sizeof(char) * ft_strlen(name));
				ft_lstaddend(possibilities, list_new);
			}	
		}
		closedir(pdir);
	}
}

/*
** private
** DESCRIPTION  : Liste toutes les possibilitées (dossier/fichier/exec) qui commence par le mot qui vien d'être entree
** EXPLICATIONS : tout d'abord on commence par supprimer l'ancienne liste si il y en à une. 
** On recherche toutes les correspondances (dossier/fichier/exec/builtins). On trie dans le sens lexycographique pour que les mots les plus petits apparaissent d'abord.
** Puis on finit par supprimer les doublon. Du genre un meme exec dans /usr/bin et dans /usr/sbin
*/
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
	int 	len;
	char 	*new_line;
	int 	i;

	shell = recover_shell();
	line = get_last_word(list_to_string(), ' ');
	len = ft_strlen(line);
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
		return (TRYING);
	if (shell->autocomplete_position == 0)
	{
		set_possibilities();
	}
	show_possibilities();
	return (READING);
}
