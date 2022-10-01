/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:17:08 by thakala           #+#    #+#             */
/*   Updated: 2022/10/01 13:51:17 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(t_prg *p)
{
	mlx_hook(p->mlx->win, ON_KEY_DOWN, 0, key_handler, p);
	mlx_hook(p->mlx->win, ON_DESTROY, 0, close_success, p);
	mlx_hook(p->mlx->win, ON_MOUSE_DOWN, 0, mouse_handler_down, p);
	mlx_hook(p->mlx->win, ON_MOUSE_MOVE, 0, mouse_handler_move, p);
	mlx_hook(p->mlx->win, ON_MOUSE_UP, 0, mouse_handler_up, p);
}
