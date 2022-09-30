/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:34:54 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 16:51:51 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_prg *p)
{
	if (key == KEY_L_CMD || key == KEY_R_CMD)
		p->ipt->key.cmd_toggled = !p->ipt->key.cmd_toggled;
	return (EXIT_SUCCESS);
}
