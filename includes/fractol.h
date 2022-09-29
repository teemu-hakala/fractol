/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:14:24 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 12:36:12 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define STR_JULIA "julia"
# define STR_MANDELBROT "mandelbrot"
# define STR_BURNINGSHIP "burningship"
# define WIN_WIDTH 1024
# define WIN_HEIGHT 720
# define WIN_NAME "thakala's fract'ol"
# define ERR_NULL_MLX "GOT NULL: p->mlx.mlx = mlx_init();\n"
# define ERR_NULL_WIN "GOT NULL: p->mlx.win = mlx_new_window();\n"

# include <stdlib.h>
# include "libft.h"

typedef enum e_fractal_type
{
	FCT_JULIA,
	FCT_MANDELBROT,
	FCT_BURNINGSHIP
}	t_type;

typedef s_fractal
{

}	t_fct;

typedef s_minilibx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef s_minilibx
{
	void	*mlx;
	void	*win;
	t_img	img;
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
void	exit_msg(const char *message, unsigned char value);

#endif
