/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/17 14:49:36 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_prompt	*init_prompt(void)
{
	t_prompt		*prompt;

	prompt = (t_prompt*)malloc(sizeof(t_prompt));
	prompt->line = NULL;
	prompt->i_position = 0;
	prompt->l_length = 0;
	prompt->p_length = get_current_folder_length();
	return (prompt);
}

char		*get_current_folder(void)
{
	char	*prompt;

	prompt = ft_strdup("");
	if (ft_strrchr_n(env_get(g_env, "PWD"), '/'))
		prompt = ft_strfjoin(prompt, ft_strrchr_n(env_get(g_env, "PWD"), '/'));
	prompt = ft_strfjoin(prompt, ft_strdup(" $> "));
	return (prompt);
}

int			get_current_folder_length(void)
{
	char	*prompt;
	int		prompt_length;

	prompt = get_current_folder();
	prompt_length = ft_strlen(prompt);
	return (prompt_length);
}