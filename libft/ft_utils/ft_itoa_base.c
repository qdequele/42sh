/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:02:34 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/08 10:42:41 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa_base(int nb, int base)
{
	char			*str;
	size_t			len;
	size_t			neg;
	long long int	n;

	n = nb;
	len = ft_nbrlen_base(n, base);
	neg = ft_isnegative(n);
	str = (char *)malloc(sizeof(char) * (neg + len + 1));
	if (str == NULL)
		return (NULL);
	str[len + neg] = '\0';
	if (neg)
	{
		str[0] = '-';
		n = -n;
	}
	while ((len-- + neg) > neg)
	{
		str[len + neg] = (n % base) + ((n % base) > 9 ? 'A' - 10 : '0');
		n = n / base;
	}
	return (str);
}
