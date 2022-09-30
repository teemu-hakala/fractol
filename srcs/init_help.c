/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:33:31 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 17:41:52 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		exit_msg(ERR_NULL_MLX, EXIT_FAILURE);
}

void	init_win(t_mlx *m)
{
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (m->win == NULL)
		exit_msg(ERR_NULL_WIN, EXIT_FAILURE);
}

void	init_img(t_mlx *m)
{
	fetch_new_image(m);
	m->img.bytes_per_pixel = m->img.bits_per_pixel / 8;
}

void	init_fct(t_fct *f)
{
	f->iter = INITIAL_ITERATIONS;
	f->zoom = 1.0L;
	f->pltt = PALETTE_GRAYSCALE;
}

void	init_ipt(t_ipt *i)
{
	i->mse.refresh = TRUE;
	i->key = (t_key){};
}
