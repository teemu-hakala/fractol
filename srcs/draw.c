/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:14 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 16:17:17 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_prg	*draw(t_prg *p)
{
	fetch_new_image(p->mlx);
	p->fct->type(p);
	mlx_put_image_to_window(p->mlx->mlx, p->mlx->win, p->mlx->img.img, 0, 0);
	mlx_destroy_image(p->mlx->mlx, p->mlx->img.img);
	return (p);
}
