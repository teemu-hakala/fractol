/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:29:41 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 12:33:55 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_prg	*init(t_prg *p)
{
	init_mlx(p->mlx);
	init_win(p->mlx);
	init_img(p->mlx);
	init_fct(p->fct);
	init_inp(p->inp);
	return (p);
}
