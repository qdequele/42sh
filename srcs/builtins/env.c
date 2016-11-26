/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/18 20:24:55 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static t_option	*builtins_env_options(void)
{
	static t_option	opt[] = {
		{'i', 0}
	};

	return (opt);
}

static t_list	*env_cpy(t_list *src)
{
	t_env		*env;
	t_list		*tmp;
	t_list		*dest;

	tmp = src;
	dest = NULL;
	while (tmp)
	{
		env = (t_env *)malloc(sizeof(t_env));
		env->key = ft_strdup(((t_env *)tmp->content)->key);
		env->value = ft_strdup(((t_env *)tmp->content)->value);
		ft_lstadd(&dest, ft_lstnew(env, sizeof(t_env)));
		tmp = tmp->next;
		free(env);
	}
	dest = ft_lst_reverse(dest);
	return (dest);
}

int				shell_core(t_list **env, char **cmds)
{
	t_list		*backup;
	char		*test;

	backup = g_env;
	g_env = *env;
	test = ft_array_to_string(cmds);
	process_input(test);
	free(test);
	g_env = backup;
	return (1);
}

int				builtins_env(t_list **env, char **cmds)
{
	t_list		*tmp_env;
	t_option	*options;
	int			i;
	char		*key;

	options = builtins_env_options();
	option_init(&options, 1);
	if (options_parser(&options, 1, cmds, "env") == 0)
		return (1);
	i = 1;
	tmp_env = (options[0].used) ? NULL : env_cpy(*env);
	while (cmds[i] && cmds[i][0] == '-')
		i++;
	while (cmds[i] && ft_strchr(cmds[i], '='))
	{
		key = ft_strsub(cmds[i], 0, ft_wordlen(cmds[i], '='));
		env_add_or_modify(&tmp_env, key, ft_strchr_n(cmds[i], '='));
		free(key);
		i++;
	}
	(cmds[i]) ? shell_core(&tmp_env, &cmds[i]) : env_show(tmp_env);
	env_free(&tmp_env);
	return (0);
}
