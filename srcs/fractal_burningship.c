/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burningship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:07:17 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 11:39:37 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	burningship_plot(t_prg *pr, t_ldbl_pt *p0)
{
	t_ldbl_pt	pt;
	t_ldbl_pt	p2;
	uint64_t	i;

	pt = (t_ldbl_pt){.row = 0.0L, .col = 0.0L};
	p2 = (t_ldbl_pt){.row = 0.0L, .col = 0.0L};
	i = 0;
	while (p2.col + p2.row <= 4.0L && i < pr->fct->iter)
	{
		pt.row = abs_ldbl(2 * pt.col * pt.row) + p0->row;
		pt.col = p2.col - p2.row + p0->col;
		p2.col = pt.col * pt.col;
		p2.row = pt.row * pt.row;
		i++;
	}
	return (palette(pr, i));
}
