/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:15:58 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 11:42:04 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	scale(long double low, int interval, long double high)
{
	return ((high - low) / (long double) interval);
}

void	mandelbrot_scales(t_ldbl_pt *p0, t_pt px)
{
	static t_scale_pt	scales;

	if (scales.calculated == FALSE)
	{
		scales = (t_scale_pt){.ver = \
			scale(-2.0L, WIN_HEIGHT, 2.0L), .hor = \
			scale(-2.5L, WIN_WIDTH, 1.5L), .calculated = TRUE};
		if (scales.ver < scales.hor)
		{
			scales.ver = scales.hor;
			scales.hor = scales.hor;
		}
		else
		{
			scales.hor = scales.ver;
			scales.ver = scales.ver;
		}
	}
	p0->col = scales.hor * px.col;
	p0->row = scales.ver * px.row;
}

void	burningship_scales(t_ldbl_pt *p0, t_pt px)
{
	static t_scale_pt	scales;

	if (scales.calculated == FALSE)
	{
		scales = (t_scale_pt){.ver = \
			scale(-2.0L, WIN_HEIGHT, 2.0L), .hor = \
			scale(-2.5L, WIN_WIDTH, 1.5L), .calculated = TRUE};
		if (scales.ver < scales.hor)
		{
			scales.ver = scales.hor;
			scales.hor = scales.hor;
		}
		else
		{
			scales.hor = scales.ver;
			scales.ver = scales.ver;
		}
	}
	p0->col = scales.hor * px.col;
	p0->row = scales.ver * px.row;
}

void	julia_scales(t_ldbl_pt *p0, t_pt px)
{
	static t_scale_pt	scales;

	if (scales.calculated == FALSE)
	{
		scales = (t_scale_pt){.ver = \
			scale(-2.0L, WIN_HEIGHT, 2.0L), .hor = \
			scale(-2.5L, WIN_WIDTH, 1.5L), .calculated = TRUE};
		if (scales.ver < scales.hor)
		{
			scales.ver = scales.hor;
			scales.hor = scales.hor;
		}
		else
		{
			scales.hor = scales.ver;
			scales.ver = scales.ver;
		}
	}
	p0->col = scales.hor * px.col;
	p0->row = scales.ver * px.row;
}

