/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:36:00 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/07 00:00:00 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *s)
{
	double	result;
	double	frac;
	double	sign;

	result = 0.0;
	frac = 1.0;
	sign = 1.0;
	if (*s == '-')
		sign = -1.0;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10.0 + (*s - '0');
		s++;
	}
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		frac /= 10.0;
		result += (*s - '0') * frac;
		s++;
	}
	return (result * sign);
}

void	parse_julia(t_fractal *fractal, char *r_str, char *i_str)
{
	fractal->julia_r = ft_atof(r_str);
	fractal->julia_i = ft_atof(i_str);
}
