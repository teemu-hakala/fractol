/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:52 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 14:22:29 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_prg *p)
{

}

void	mandelbrot(t_prg *pr)
{
	t_pt		px;
	t_ldbl_pt	p0;

	px = (t_pt){.row = 0, .col = 0};
	while (px.row < WIN_WIDTH)
	{
		while (px.col < WIN_HEIGHT)
		{
			p0 = (t_ldbl_pt){.row = scale(-1.12L, px.row, 1.12L), \
				.col = scale(-2.00L, px.row, 0.47L)};
			mandelbrot_plot(pr, &p0);
			px.col++;
		}
		px.row++;
	}
}

void	burningship(t_prg *p)
{

}
