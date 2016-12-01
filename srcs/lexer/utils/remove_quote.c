/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <bjamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:21:13 by qdequele          #+#    #+#             */
/*   Updated: 2016/12/01 13:24:09 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*ft_remove_quote(char *word)
{
	if (word[0] == '\'' || word[0] == '"' || word[0] == '`'
		|| word[0] == '(')
		return (ft_strsub(word, 1, ft_strlen(word) - 2));
	return (word);
}
