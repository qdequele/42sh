/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 12:28:23 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/21 16:03:21 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_match(char *s1, char *s2)
{
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && *s1 != '*')
		return (ft_match(s1 + 1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*' && *(s2 + 1) == '*')
		return (ft_match(s1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*' && *s1 == *(s2 + 1))
		return (ft_match(s1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*')
		return (ft_match(s1 + 1, s2) || (ft_match(s1, s2 + 1)));
	else if (*s1 == '\0' && *s2 == '*')
		return (ft_match(s1, s2 + 1));
	if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}
