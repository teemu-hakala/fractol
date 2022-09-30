/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_graphs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:35:21 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 11:14:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	eight_bit_color_graph_sqrt_x_flip(long double iter_perc)
{
	return (1.0L - sqrtl(iter_perc));
}
