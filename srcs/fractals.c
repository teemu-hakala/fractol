/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:52 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 17:39:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_prg *p)
{
	(void)p;
}

void	mandelbrot(t_prg *pr)
{
	t_pt				px;
	t_ldbl_pt			p0;

	px.row = 0;
	while (px.row < WIN_HEIGHT)
	{
		px.col = 0;
		while (px.col < WIN_WIDTH)
		{
			mandelbrot_scales(&p0, px);
			pixelput(&pr->mlx->img, px.col, px.row, mandelbrot_plot(pr, &p0));
			px.col++;
		}
		px.row++;
	}
}

void	burningship(t_prg *p)
{
	(void)p;
}
