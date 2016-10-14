/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/14 16:54:06 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	print_shell(void)
{
	char	*prompt;

	prompt = ft_strdup("");
	if (ft_strrchr_n(env_get(g_env, "PWD"), '/'))
		prompt = ft_strfjoin(prompt, ft_strrchr_n(env_get(g_env, "PWD"), '/'));
	prompt = ft_strfjoin(prompt, ft_strdup(" $> "));
	ft_putstr_c(CYAN, prompt);
}

void	print_shell_err(char *s)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\e[0m", 2);
}
