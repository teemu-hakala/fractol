/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:14:24 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 11:57:15 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define STR_JULIA "julia"
# define STR_MANDELBROT "mandelbrot"
# define STR_BURNINGSHIP "burningship"

# include <stdlib.h>

typedef enum e_fractal_type
{
	FCT_JULIA,
	FCT_MANDELBROT,
	FCT_BURNINGSHIP
}	t_type;

typedef s_fractal
{

}	t_fct;

typedef s_minilibx
{

}	t_mlx;

typedef s_mouse
{

}	t_mse;

typedef s_keyboard
{

}	t_key;

typedef s_user_inputs
{
	t_mse	mse;
	t_key	key;
}	t_ipt;

typedef struct s_program
{
	t_fct	*fct;
	t_mlx	*mlx;
	t_ipt	*inp;
}	t_prg;

void	usage(void);

#endif
