/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:02:47 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 13:37:27 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop(t_prg *p)
{
	// mlx_loop_hook(p->mlx->mlx, vary_julia_constant, p);
	mlx_loop(p->mlx->mlx);
	return (EXIT_SUCCESS);
}
