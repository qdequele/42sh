/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/03/03 13:19:51 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int			main(int argc, char **argv, char **environ)
{
	UNUSED(argv);
	g_env = NULL;
	if (argc > 1)
	{
		ft_putendl_fd("21sh cannot have arguments", 2);
		return (0);
	}
	ft_console_log_clear();
	ft_console_log("start 42sh\n\n");
	env_parse_to_list(&g_env, environ);
	init_signals();
	if (init_term() == -1)
	{
		ft_putendl_fd("21sh cannot be launch without termcaps", 2);
		reset_term();
		return (0);
	}
	shell_get_lines();
	reset_term();
	return (0);
}

// test de str_split_str
// int main(void)
// {
// 	char 	*str;
// 	char 	**res;
// 	int 	i;

// 	str = ft_strdup("ls toto && tata && pouet tutu && pwd");
// 	res = str_split_str(str, "&&");
// 	i = 0;
// 	while (res[i])
// 	{
// 		printf("str[%i] = |%s|\n", i, res[i]);
// 		i++;
// 	}
// 	return (0);
// }
