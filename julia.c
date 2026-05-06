/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:00:15 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 20:00:39 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_fractal *fractal)
{
	t_complex	c;
	int			i;

	c.r = fractal->julia_r;
	c.i = fractal->julia_i;
	i = 0;
	while (i < fractal->max_iter)
	{
		z = sum_cplx(sqr_cplx(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4.0)
			return (i);
		i++;
	}
	return (fractal->max_iter);
}
