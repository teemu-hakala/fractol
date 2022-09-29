/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:15:58 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 17:40:31 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


long double	scale(long double low, int interval, int pos, long double high)
{
	return ((high - low) / (long double) interval * (long double) pos);
}

void	mandelbrot_scales(t_ldbl_pt *p0, t_pt px)
{
	t_ldbl_pt	scales;

	scales = (t_ldbl_pt){.row = scale(-1.12L, WIN_HEIGHT, px.row, 1.12L), \
		.col = scale(-2.00L, WIN_WIDTH, px.col, 0.47L)};
	if (scales.row < scales.col)
	{
		p0->row = scales.row;
		p0->col = scales.row;
	}
	else
	{
		p0->row = scales.col;
		p0->col = scales.col;
	}// (shorten to alternative ternary)
}
