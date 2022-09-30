/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:21:35 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 14:30:55 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_register_click_down(int btn, int x, int y, t_prg *p)
{
	(void)btn;
	p->ipt->mse.prev = p->ipt->mse.curr;
	p->ipt->mse.curr = (t_pt){.row = y, .col = x};
	p->ipt->mse.isdown = TRUE;
}

void	mouse_register_click_up(int btn, int x, int y, t_prg *p)
{
	(void)btn;
	p->ipt->mse.prev = p->ipt->mse.curr;
	p->ipt->mse.curr = (t_pt){.row = y, .col = x};
	p->ipt->mse.isdown = FALSE;
}
