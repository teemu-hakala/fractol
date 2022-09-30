/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:10:38 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 17:11:57 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_msg(const char *message, unsigned char value)
{
	ft_putstr(message);
	exit(value);
}

int	close_success(void)
{
	exit_msg("Great success!\n", EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
