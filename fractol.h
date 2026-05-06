/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:11:39 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 20:04:31 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define WIDTH	800
#define HEIGHT	800
#define ERROR_MSG "\"mandlebrot\" or \"julia <r> <i>\" supported only\n"
#define ZOOM_IN	0.9
#define ZOOM_OUT 1.1

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pixel_buffer;
	int	bits_per_pixel;
	int	line_len;
	int	endian;

	char	*name;
	double	x_min;
	double	x_max;
	double  y_min;
	double	y_max;
	double	julia_r;
	double	julia_i;
	int	max_iter;
	int	color_shift;
}	t_fractal;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

/*libft_functions*/
int	ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);

/*init functions*/
int	cleanup_fractal(t_fractal *fractal);
void	init_bounds(t_fractal *fractal);
void	init_hooks(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);

/*render functions*/
void	render(t_fractal *fractal);
void	draw_pixel(t_fractal *fractal, int x, int y, int color);

/*math functions*/
t_complex	sum_cplx(t_complex z1, t_complex z2);
t_complex	sqr_cplx(t_complex z);
int	julia(t_complex z, t_fractal *fractal);
int	mandelbrot(t_complex z, t_fractal *fractal);

/*hook functions*/
int	keyboard_exit(int keysym, void *param);
int	window_exit(void *param);
int	handle_zoom(int button, int x, int y, void *param);

/*utils*/
double	map(double value, double in_min, double in_max,
			double out_min, double out_max);
#endif