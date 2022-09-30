/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotators.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:44:11 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 17:46:00 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rotate_colour(t_prg *p)
{
	if (p->fct->pltt == PALETTE_GRAYSCALE)
		p->fct->pltt = PALETTE_MONO_RED;
	else if (p->fct->pltt == PALETTE_MONO_RED)
		p->fct->pltt = PALETTE_MONO_GRN;
	else if (p->fct->pltt == PALETTE_MONO_GRN)
		p->fct->pltt = PALETTE_MONO_BLU;
	else if (p->fct->pltt == PALETTE_MONO_BLU)
		p->fct->pltt = PALETTE_GRAYSCALE;
}
