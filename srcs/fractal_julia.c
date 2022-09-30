/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:52 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 13:00:44 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
