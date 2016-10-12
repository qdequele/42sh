/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:01:32 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/19 13:07:36 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_matrix	*ft_matrix_rotate_x(double beta)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	m->a1 = 1;
	m->b2 = cos(beta);
	m->b3 = -sin(beta);
	m->c2 = sin(beta);
	m->c3 = cos(beta);
	m->d4 = 1;
	return (m);
}

t_matrix	*ft_matrix_rotate_y(double beta)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	m->a1 = cos(beta);
	m->a3 = sin(beta);
	m->b2 = 1;
	m->c1 = -sin(beta);
	m->c3 = cos(beta);
	m->d4 = 1;
	return (m);
}

t_matrix	*ft_matrix_rotate_z(double beta)
{
	t_matrix *m;

	if (!(m = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	m->a1 = cos(beta);
	m->a2 = -sin(beta);
	m->b1 = sin(beta);
	m->b2 = cos(beta);
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

t_matrix	*ft_matrix_translate(double tx, double ty, double tz)
{
	t_matrix *m;

	if (!(m = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	m->a4 = tx;
	m->b4 = ty;
	m->c4 = tz;
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

t_matrix	*ft_matrix_scale(double scale)
{
	t_matrix *m;

	if (!(m = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	m->a1 = scale;
	m->b2 = scale;
	m->c3 = scale;
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}
