/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:25:08 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 13:36:47 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler_scroll_up(t_prg *p, t_pt *mse)
{
	(void)mse;
	p->fct->zoom *= 1.1L;
	return (EXIT_SUCCESS);
}

int	mouse_handler_scroll_dn(t_prg *p, t_pt *mse)
{
	(void)mse;
	p->fct->zoom /= 1.1L;
	return (EXIT_SUCCESS);
}

int	mouse_handler_down(int btn, int x, int y, t_prg *p)
{
	return (((t_hndlr)(
			(uint64_t)mouse_handler_scroll_up * (btn == SCROLL_UP)
			+ (uint64_t)mouse_handler_scroll_dn * (btn == SCROLL_DN)
		))(p, &(t_pt){.row = y, .col = x}));
}
