/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:23:57 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 20:08:09 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	offset;

	offset = (fractal->line_len * y) + (x * (fractal->bits_per_pixel / 8));
	*((unsigned int *)(offset + fractal->pixel_buffer)) = color;
}

void	render(t_fractal *fractal)
{
	t_complex	z;
	int			x;
	int			y;
	int			iter;
	int			is_mandelbrot;

	is_mandelbrot = !ft_strncmp(fractal->name, "mandelbrot", 10);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.r = map(x, 0, WIDTH, fractal->x_min, fractal->x_max);
			z.i = map(y, 0, HEIGHT, fractal->y_min, fractal->y_max);
			if (is_mandelbrot)
				iter = mandelbrot(z, fractal);
			else
				iter = julia(z, fractal);
			draw_pixel(fractal, x, y, iter * fractal->color_shift);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}