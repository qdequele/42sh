/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrbase_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:42:57 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/08 10:59:02 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_nbrlen_base(int nb, int base)
{
	int		len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}
