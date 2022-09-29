/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:39:07 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 15:26:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	palette_blue(t_prg *pr, uint64_t iter)
{
	long double	intensity_percentage;

	intensity_percentage = (long double) iter / (long double) pr->fct->iter;
	return ((int)(0xFF * intensity_percentage) << RGB_BLU);
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
		if (pr->fct->pltt == PALETTE_BLUE)
			return (palette_blue(pr, iteration));
	}
	return (0);
}
