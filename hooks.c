/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:55:18 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/07 11:54:41 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_exit(int keysym, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keysym == XK_Escape)
	{
		cleanup_fractal(fractal);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	window_exit(void *param)
{
	cleanup_fractal((t_fractal *)param);
	exit(EXIT_SUCCESS);
}

void	zoom_bounds(t_fractal *fractal, double factor, int x, int y)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = map(x, WIDTH, fractal->x_min, fractal->x_max);
	mouse_i = map(y, HEIGHT, fractal->y_min, fractal->y_max);
	fractal->x_min = mouse_r + (fractal->x_min - mouse_r) * factor;
	fractal->x_max = mouse_r + (fractal->x_max - mouse_r) * factor;
	fractal->y_min = mouse_i + (fractal->y_min - mouse_i) * factor;
	fractal->y_max = mouse_i + (fractal->y_max - mouse_i) * factor;
}

int	handle_zoom(int button, int x, int y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	(void)x;
	(void)y;
	if (button == 4)
	{
		zoom_bounds(fractal, ZOOM_IN, x, y);
	}
	else if (button == 5)
	{
		zoom_bounds(fractal, ZOOM_OUT, x, y);
	}
	render(fractal);
	return (0);
}
