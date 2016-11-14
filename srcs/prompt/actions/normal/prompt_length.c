/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/11/06 18:52:25 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static char	*get_current_folder(void)
{
	char	*prompt;

	prompt = ft_strdup("");
	if (ft_strrchr_n(env_get(g_env, "PWD"), '/'))
		prompt = ft_strfjoin(prompt, ft_strrchr_n(env_get(g_env, "PWD"), '/'));
	prompt = ft_strfjoin(prompt, " $> ");
	return (prompt);
}

int			get_normal_prompt_length(void)
{
	char	*prompt;
	int		prompt_length;

	prompt = get_current_folder();
	prompt_length = ft_strlen(prompt);
	free(prompt);
	return (prompt_length);
}
