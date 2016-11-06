/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_generic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:43:35 by qdequele          #+#    #+#             */
/*   Updated: 2016/04/13 21:54:41 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		is_token(char *str)
{
	int		i;

	i = 0;
	while (g_token_matcher[i].type != TOKEN_TYPE_END_LIST)
	{
		if (g_token_matcher[i].match_function(str) != 0)
			return (1);
		i++;
	}
	return (0);
}
