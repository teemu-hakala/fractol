/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:25:08 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 14:39:57 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler_scroll_up(t_prg *p, t_pt *mse)
{
	(void)mse;
	p->fct->zoom *= 1.1L;
	p->fct->iter /= 1.07L;
	return (EXIT_SUCCESS);
}

int	mouse_handler_scroll_dn(t_prg *p, t_pt *mse)
{
	(void)mse;
	p->fct->zoom /= 1.1L;
	p->fct->iter *= 1.07L;
	return (EXIT_SUCCESS);
}

int	mouse_handler_down(int btn, int x, int y, t_prg *p)
{
	if (btn != SCROLL_UP && btn != SCROLL_DN && btn != LEFT_CLICK)
		return (EXIT_SUCCESS);
	p->ipt->mse.refresh = TRUE;
	if (btn == LEFT_CLICK)
		mouse_register_click_down(btn, x, y, p);
	else
		((t_hndlr)(
			(uint64_t)mouse_handler_scroll_up * (btn == SCROLL_UP)
			+ (uint64_t)mouse_handler_scroll_dn * (btn == SCROLL_DN)
		))(p, &(t_pt){.row = y, .col = x});
	draw(p);
	p->ipt->mse.refresh = FALSE;
	return (EXIT_SUCCESS);
}

int	mouse_handler_move(int x, int y, t_prg *p)
{
	if (p->ipt->mse.isdown == TRUE)
	{
		p->ipt->mse.prev = p->ipt->mse.curr;
		p->ipt->mse.diff = (t_pt){.row = y - p->ipt->mse.curr.row, \
			.col = x - p->ipt->mse.curr.col};
		pan(p);
		p->ipt->mse.curr = (t_pt){.row = y, .col = x};
		return (!draw(p));
	}
	return (EXIT_SUCCESS);
}

int	mouse_handler_up(int btn, int x, int y, t_prg *p)
{
	if (btn != LEFT_CLICK)
		return (EXIT_SUCCESS);
	p->ipt->mse.refresh = TRUE;
	if (btn == LEFT_CLICK)
		mouse_register_click_up(btn, x, y, p);
	draw(p);
	p->ipt->mse.refresh = FALSE;
	return (EXIT_SUCCESS);
}
