/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:15:58 by thakala           #+#    #+#             */
/*   Updated: 2022/10/01 13:49:34 by thakala          ###   ########.fr       */
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
			scale(-2.0L, WIN_HEIGHT, 2.0L) * pr->fct->zoom, .hor = \
			scale(-2.5L, WIN_WIDTH, 1.5L) * pr->fct->zoom, .calculated = TRUE};
		if (scales.ver < scales.hor)
			scales.ver = scales.hor;
		else
			scales.hor = scales.ver;
	}
	p0->row = scales.ver * (px.row - pr->fct->center.row / pr->fct->zoom);
	p0->col = scales.hor * (px.col - pr->fct->center.col / pr->fct->zoom);
}

void	burning_ship_scales(t_prg *pr, t_ldbl_pt *p0, t_pt px)
{
	static t_scale_pt	scales;

	if (scales.calculated == FALSE || pr->ipt->mse.refresh == TRUE)
	{
		scales = (t_scale_pt){.ver = \
			scale(-2.0L, WIN_HEIGHT, 2.0L) * pr->fct->zoom, .hor = \
			scale(-2.5L, WIN_WIDTH, 1.5L) * pr->fct->zoom, .calculated = TRUE};
		if (scales.ver < scales.hor)
			scales.ver = scales.hor;
		else
			scales.hor = scales.ver;
	}
	p0->row = scales.ver * (px.row - pr->fct->center.row / pr->fct->zoom);
	p0->col = scales.hor * (px.col - pr->fct->center.col / pr->fct->zoom);
}

void	julia_scales(t_prg *pr, t_ldbl_pt *p0, t_pt px)
{
	static t_scale_pt	scales;

	if (scales.calculated == FALSE || pr->ipt->mse.refresh == TRUE)
	{
		scales = (t_scale_pt){.ver = \
			scale(-2.0L, WIN_HEIGHT, 2.0L) * pr->fct->zoom, .hor = \
			scale(-2.0L, WIN_WIDTH, 2.0L) * pr->fct->zoom, .calculated = TRUE};
		if (scales.ver < scales.hor)
			scales.ver = scales.hor;
		else
			scales.hor = scales.ver;
	}
	p0->row = scales.ver * (px.row - pr->fct->center.row / pr->fct->zoom);
	p0->col = scales.hor * (px.col - pr->fct->center.col / pr->fct->zoom);
}
