/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:52 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 13:09:54 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	vary_julia_constant(t_prg *p)
{
	p->fct->constant.row += 0.01L;
	p->fct->constant.col += 0.01L;
	julia(p);
	draw(p);
	return (EXIT_SUCCESS);
}

unsigned int	julia_plot(t_prg *pr, t_ldbl_pt *z)
{
	uint64_t	i;
	long double	col_tmp;

	i = 0;
	while (z->col + z->row <= 4.0L && i < pr->fct->iter)
	{
		col_tmp = z->col * z->col - z->row * z->row;
		z->row = 2 * z->col * z->row + pr->fct->constant.row;
		z->col = col_tmp + pr->fct->constant.col;
		i++;
	}
	return (palette(pr, i));
}
