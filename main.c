/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:59:48 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 19:30:25 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	 || (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	 {
		fractal.name = av[1];
		init_fractal(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
		return (0);
	 }
	 else
	 {
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	 }
}
