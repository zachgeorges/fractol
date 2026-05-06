/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:02:49 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 16:10:21 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_cplx(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.r = z1.r + z2.r;
	res.i = z1.i + z2.i;
	return (res);
}

t_complex	sqr_cplx(t_complex z)
{
	t_complex	res;

	res.r = (z.r * z.r) - (z.i * z.i);
	res.i = 2 * z.r * z.i;
	return (res);
}

