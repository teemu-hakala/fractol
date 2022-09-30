/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:15:58 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 14:10:08 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	scale(long double low, int interval, long double high)
{
	return ((high - low) / (long double) interval);
}

void	mandelbrot_scales(t_prg *pr, t_ldbl_pt *p0, t_pt px)
{
	static t_scale_pt	scales;

	if (scales.calculated == FALSE || pr->ipt->mse.refresh == TRUE)
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
	if (pr->ipt->mse.refresh == TRUE)
	{
		scales = (t_scale_pt){.ver = scales.ver * pr->fct->zoom, \
			.hor = scales.hor * pr->fct->zoom, .calculated = TRUE};
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

