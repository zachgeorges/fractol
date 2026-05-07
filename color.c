/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:36:23 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/07 00:00:00 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	lerp_color(int c1, int c2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((c1 >> 16 & 0xFF) * (1 - t)) + ((c2 >> 16 & 0xFF) * t));
	g = (int)(((c1 >> 8 & 0xFF) * (1 - t)) + ((c2 >> 8 & 0xFF) * t));
	b = (int)(((c1 & 0xFF) * (1 - t)) + ((c2 & 0xFF) * t));
	return (r << 16 | g << 8 | b);
}

int	get_color(int iter, t_fractal *fractal)
{
	double	t;

	if (iter == fractal->max_iter)
		return (COLOR_SET);
	t = (double)iter / fractal->max_iter;
	return (lerp_color(COLOR_START, COLOR_END, t));
}
