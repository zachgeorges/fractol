/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:53:46 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 20:09:33 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, t_fractal *fractal)
{
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
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