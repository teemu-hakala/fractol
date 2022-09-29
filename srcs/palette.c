/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:39:07 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 15:33:17 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	palette_mono(t_prg *pr, uint64_t iter, t_rgb ch)
{
	long double	intensity_percentage;

	intensity_percentage = (long double) iter / (long double) pr->fct->iter;
	return ((int)(0xFF * intensity_percentage) << ch);
}

static int	palette_grayscale(t_prg *pr, uint64_t iter)
{
	long double	intensity_percentage;

	intensity_percentage = (long double) iter / (long double) pr->fct->iter;
	return ((int)(0xFF * intensity_percentage) << RGB_RED \
		| (int)(0xFF * intensity_percentage) << RGB_GRN \
		| (int)(0xFF * intensity_percentage) << RGB_BLU);
}

int	palette(t_prg *pr, uint64_t iteration)
{
	if (iteration != pr->fct->iter)
	{
		if (pr->fct->pltt == PALETTE_GRAYSCALE)
			return (palette_grayscale(pr, iteration));
		return (palette_mono(pr, iteration, 8 * pr->fct->pltt));
	}
	return (0);
}
