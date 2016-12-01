/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_generic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:24:13 by bjamin           ###   ########.fr       */
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
