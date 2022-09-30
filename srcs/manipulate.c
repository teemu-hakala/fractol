/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:35:33 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 17:07:02 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan(t_prg *p)
{
	p->fct->center = (t_pt){.row = p->fct->center.row + \
		p->ipt->mse.diff.row * p->fct->zoom, \
		.col = p->fct->center.col + p->ipt->mse.diff.col * p->fct->zoom};
}
