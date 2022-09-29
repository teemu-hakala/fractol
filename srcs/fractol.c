/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:17:26 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 16:06:30 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_type(t_fct *fractal, char *input)
{
	if (ft_strcmp(input, STR_JULIA) == EXIT_SUCCESS)
		fractal->type = julia;
	else if (ft_strcmp(input, STR_MANDELBROT) == EXIT_SUCCESS)
		fractal->type = mandelbrot;
	else if (ft_strcmp(input, STR_BURNINGSHIP) == EXIT_SUCCESS)
		fractal->type = burningship;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	static t_mlx	mlx;
	static t_fct	fct;
	static t_ipt	ipt;
	t_prg			prg;

	if (argc != 2 || EXIT_SUCCESS != fractal_type(&fct, argv[1]))
		usage();
	prg = (t_prg){.fct = &fct, .mlx = &mlx, .ipt = &ipt};
	return (loop(draw(init(&prg))));
}
