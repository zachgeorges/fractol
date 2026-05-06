/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:55:18 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 19:47:37 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_exit(int keysym, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keysym == XK_Escape)
		cleanup_fractal(fractal);
	return (0);
}

int	window_exit(void *param)
{
	cleanup_fractal((t_fractal *)param);
	return (0);
}

int	handle_zoom(int button, int x, int y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->x_min *= ZOOM_IN;
		fractal->x_max *= ZOOM_IN;
		fractal->y_min *= ZOOM_IN;
		fractal->y_max *= ZOOM_IN;
	}
	else if (button == 5)
	{
		fractal->x_min *= ZOOM_OUT;
		fractal->x_max *= ZOOM_OUT;
		fractal->y_min *= ZOOM_OUT;
		fractal->y_max *= ZOOM_OUT;
	}
	render(fractal);
	return (0);
}