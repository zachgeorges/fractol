/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:23:48 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/07 11:55:23 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cleanup_fractal(t_fractal *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	return (0);
}

void	init_error(t_fractal *fractal)
{
	ft_putstr_fd("Error: initialization failed\n", STDERR_FILENO);
	cleanup_fractal(fractal);
	exit(EXIT_FAILURE);
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
	fractal->max_iter = MAX_ITER;
	fractal->color_shift = 1;
}

void	init_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, keyboard_exit, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask,
		window_exit, fractal);
	mlx_hook(fractal->win, ButtonPress, ButtonPressMask, handle_zoom, fractal);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = NULL;
	fractal->win = NULL;
	fractal->img = NULL;
	fractal->pixel_buffer = NULL;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		init_error(fractal);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (!fractal->win)
		init_error(fractal);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		init_error(fractal);
	fractal->pixel_buffer = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->line_len,
			&fractal->endian);
	if (!fractal->pixel_buffer)
		init_error(fractal);
	init_bounds(fractal);
	init_hooks(fractal);
}
