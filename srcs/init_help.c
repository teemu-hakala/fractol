/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:33:31 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 15:51:57 by thakala          ###   ########.fr       */
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
	m->img.img = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT);
	m->img.addr = mlx_get_data_addr(m->img.img, &m->img.bits_per_pixel, \
		&m->img.line_length, &m->img.endian);
	m->img.bytes_per_pixel = m->img.bits_per_pixel / 8;
}

void	init_fct(t_fct *f)
{
	f->iter = 10;
	f->zoom = 1;
	f->pltt = PALETTE_GRAYSCALE;
}

void	init_ipt(t_ipt *i)
{
	i->mse = (t_mse){};
	i->key = (t_key){};
}
