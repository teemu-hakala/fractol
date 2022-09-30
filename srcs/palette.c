/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:39:07 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 11:32:53 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int	palette_mono(t_prg *pr, uint64_t iter, t_rgb ch)
{
	long double	iteration_percentage;

	iteration_percentage = (long double) iter / (long double) pr->fct->iter;
	return ((unsigned int) \
		(eight_bit_color_graph_sqrt_x_flip(iteration_percentage)) << ch);
}

static unsigned int	palette_grayscale(t_prg *pr, uint64_t iter)
{
	long double		iteration_percentage;
	unsigned int	colour_intensity;

	iteration_percentage = (long double) iter / (long double) pr->fct->iter;
	colour_intensity = (unsigned int)(0xFF * \
		eight_bit_color_graph_sqrt_x_flip(iteration_percentage));
	return (colour_intensity << RGB_RED \
		| colour_intensity << RGB_GRN \
		| colour_intensity << RGB_BLU);
}

unsigned int	palette(t_prg *pr, uint64_t iteration)
{
	if (iteration != pr->fct->iter)
	{
		if (pr->fct->pltt == PALETTE_GRAYSCALE)
			return (palette_grayscale(pr, iteration));
		return (palette_mono(pr, iteration, 8 * pr->fct->pltt));
	}
	return (0);
}
