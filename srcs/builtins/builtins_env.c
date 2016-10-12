/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:17 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:32:52 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

static t_option	*builtins_env_options(void)
{
	static t_option	opt[] = {
		{'i', 0}
	};

	return (opt);
}

static t_list	*env_cpy(t_list *src)
{
	t_env	*env;
	t_list	*tmp;
	t_list	*dest;

	tmp = src;
	dest = NULL;
	while (tmp)
	{
		env = (t_env *)malloc(sizeof(t_env));
		env->key = ft_strdup(((t_env *)tmp->content)->key);
		env->value = ft_strdup(((t_env *)tmp->content)->value);
		ft_lstadd(&dest, ft_lstnew(env, sizeof(t_env)));
		tmp = tmp->next;
	}
	dest = ft_lst_reverse(dest);
	return (dest);
}

int				builtins_env(t_list **env, char **cmds)
{
	t_list		*tmp_env;
	t_option	*options;
	int			i;

	options = builtins_env_options();
	option_init(&options, 1);
	if (options_parser(&options, 1, cmds, "env") == 0)
		return (0);
	i = 1;
	tmp_env = (options[0].used) ? NULL : env_cpy(*env);
	while (cmds[i] && cmds[i][0] == '-')
		i++;
	while (cmds[i] && ft_strchr(cmds[i], '='))
	{
		env_add_or_modify(&tmp_env, ft_strsub(cmds[i], 0,
			ft_wordlen(cmds[i], '=')), ft_strchr_n(cmds[i], '='));
		i++;
	}
	if (cmds[i])
		shell_core(&tmp_env, &cmds[i]);
	else
		env_show(tmp_env);
	return (1);
}
