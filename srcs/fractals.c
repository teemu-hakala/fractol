/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:52 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 11:34:24 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_prg *pr)
{
	(void)p;
}

void	mandelbrot(t_prg *pr)
{
	t_pt		px;
	t_ldbl_pt	p0;

	px.row = -WIN_HEIGHT / 2;
	while (px.row < WIN_HEIGHT / 2)
	{
		px.col = -WIN_WIDTH / 2;
		while (px.col < WIN_WIDTH / 2)
		{
			mandelbrot_scales(&p0, px);
			pixelput(&pr->mlx->img, px.col + WIN_WIDTH / 2, \
				px.row + WIN_HEIGHT / 2, (int)mandelbrot_plot(pr, &p0));
			px.col++;
		}
		px.row++;
	}
}

void	burningship(t_prg *pr)
{
	t_pt		px;
	t_ldbl_pt	p0;

	px.row = -WIN_HEIGHT / 2;
	while (px.row < WIN_HEIGHT / 2)
	{
		px.col = -WIN_WIDTH / 2;
		while (px.col < WIN_WIDTH / 2)
		{
			burningship_scales(&p0, px);
			pixelput(&pr->mlx->img, px.col + WIN_WIDTH / 2, \
				px.row + WIN_HEIGHT / 2, (int)burningship_plot(pr, &p0));
			px.col++;
		}
		px.row++;
	}
}
