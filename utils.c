/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:03:21 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/06 20:03:47 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, double in_min, double in_max,
			double out_min, double out_max)
{
	return (out_min + (value - in_min)
		* (out_max - out_min) / (in_max - in_min));
}
