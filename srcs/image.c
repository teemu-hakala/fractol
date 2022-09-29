/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:02:44 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 16:14:27 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fetch_new_image(t_mlx *m)
{
	m->img.img = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT);
	m->img.addr = mlx_get_data_addr(m->img.img, &m->img.bits_per_pixel, \
		&m->img.line_length, &m->img.endian);
}
