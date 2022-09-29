/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_graphs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:35:21 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 15:43:03 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	eight_bit_color_graph_sqrt_x_flip(long double iter_perc)
{
	return ((long double)TWO_POW_EIGHT - \
		sqrtl((long double)TWO_POW_EIGHT * (iter_perc - 1.0L)) - 1.0L);
}
