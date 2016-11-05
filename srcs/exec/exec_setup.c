/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 16:54:22 by nathan            #+#    #+#             */
/*   Updated: 2016/04/20 16:47:14 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static char		**default_command(void)
{
	char	**av;

	__DEBUG__
	av = malloc(sizeof(char *) * 2);
	av[0] = ft_strdup("cat");
	av[1] = NULL;
	return (av);
}

static char		*path_join(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	__DEBUG__
	if (!s1 || (s1 && !*s1))
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (s1[ft_strlen(s1) - 1] == '/')
		return (ft_strjoin(s1, s2));
	tmp = ft_strjoin(s1, "/");
	res = ft_strjoin(tmp, s2);
	free(tmp);
	return (res);
}

static int		is_binary_in_folder(char *path, char *bin)
{
	DIR				*dirptr;
	struct dirent	*elem;

	__DEBUG__
	dirptr = opendir(path);
	if (!dirptr)
		return (0);
	while ((elem = readdir(dirptr)))
	{
		if (ft_strcmp(elem->d_name, bin) == 0)
		{
			closedir(dirptr);
			return (1);
		}
	}
	closedir(dirptr);
	return (0);
}

static void		find_path_binary(char **av, char *path)
{
	char	**folders;
	char	*bin_path;
	int		i;

	__DEBUG__
	if (!path || builtins_find(*av))
		return ;
	if (!(folders = ft_strsplit(path, ':')))
		return ;
	i = 0;
	while (folders[i])
	{
		if (is_binary_in_folder(folders[i], av[0]))
		{
			bin_path = path_join(folders[i], av[0]);
			free(av[0]);
			av[0] = bin_path;
			break ;
		}
		i++;
	}
	ft_free_aoc(folders);
}

void			prepare_job(t_job *j)
{
	t_list		*process_list;
	t_process	*p;
	char		*path;

	__DEBUG__
	path = env_get(g_env, "PATH");
	process_list = j->process_list;
	while (process_list)
	{
		if (!(p = process_list->content))
			return ;
		if (!p->argv || (p->argv && !*(p->argv)))
			p->argv = default_command();
		find_path_binary(p->argv, path);
		process_list = process_list->next;
	}
}
