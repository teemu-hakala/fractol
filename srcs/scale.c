/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:15:58 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 10:49:40 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	scale(long double low, int interval, long double high)
{
	return ((high - low) / (long double) interval);
}

long double	scaler(long double target_scale, int pixel_span_0)
{
	return (target_scale / (long double) pixel_span_0);
}

void	mandelbrot_scales(t_ldbl_pt *p0, t_pt px)
{
	static t_scale_pt	scales;

	if (scales.calculated == FALSE)
	{
		scales = (t_scale_pt){.ver = \
			scale(-1.12L, WIN_HEIGHT, 1.12L), .hor = \
			scale(-2.00L, WIN_WIDTH, 0.47L), .calculated = TRUE};
		if (scales.ver < scales.hor)
		{
			scales.ver = scaler(scales.hor * px.row, px.col);
			scales.hor = scales.hor;
		}
		else
		{
			scales.hor = scaler(scales.ver * px.col, px.row);
			scales.ver = scales.ver;
		}
	}
	p0->col = scales.hor * px.col;
	p0->row = scales.ver * px.row;
	/*t_ldbl_pt	scales;

	scales = (t_ldbl_pt){.row = scale(-1.12L, WIN_HEIGHT, px.row, 1.12L), \
		.col = scale(-2.00L, WIN_WIDTH, px.col, 0.47L)};
	p0->row = scales.row;
	p0->col = scales.col;*/
	/*if (scales.row < scales.col)
	{
		p0->row = scales.row;
		p0->col = scales.row;
	}
	else
	{
		p0->row = scales.col;
		p0->col = scales.col;
	}*/// (shorten to alternative ternary)
}
