/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:23:48 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 20:12:05 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cleanup_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}
void	init_bounds(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		fractal->x_min = -2.0;
		fractal->x_max = 0.5;
		fractal->y_min = -1.5;
		fractal->y_max = 1.5;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->x_min = -2.0;
		fractal->x_max = 2.0;
		fractal->y_min = -2.0;
		fractal->y_max = 2.0;
	}
	fractal->max_iter = 42;
	fractal->color_shift = 1;
}

void	init_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, keyboard_exit, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, window_exit, fractal);
	mlx_hook(fractal->win, ButtonPress, ButtonPressMask, handle_zoom, fractal);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->pixel_buffer = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->line_len,
			&fractal->endian);
	init_bounds(fractal);
	init_hooks(fractal);
}