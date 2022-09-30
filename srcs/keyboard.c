/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:34:54 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 17:12:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_prg *p)
{
	if (key == KEY_ESC)
		exit_msg("Exited successfully!\n", EXIT_SUCCESS);
	if (key == KEY_L_CMD || key == KEY_R_CMD)
		p->ipt->key.cmd_toggled = !p->ipt->key.cmd_toggled;
	return (EXIT_SUCCESS);
}
