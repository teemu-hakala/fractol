/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:14:24 by thakala           #+#    #+#             */
/*   Updated: 2022/09/29 13:16:34 by thakala          ###   ########.fr       */
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
# include "mlx.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_point
{
	int		row;
	int		col;
}	t_pt;

typedef void	(*t_ftype)(t_prg *);

typedef struct s_fractol
{
	t_ftype		type;
	uint64_t	iter;
	uint64_t	zoom; //perhaps a floating-point type instead?
}	t_fct;

typedef struct s_minilibx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_minilibx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_mouse
{
	t_pt	prev;
	t_pt	curr;
	t_pt	diff;
	t_bool	isdown;
}	t_mse;

typedef struct s_keyboard
{
	t_bool	cmd_toggled;
}	t_key;

typedef struct s_user_inputs
{
	t_mse	mse;
	t_key	key;
}	t_ipt;

typedef struct s_program
{
	t_fct	*fct;
	t_mlx	*mlx;
	t_ipt	*ipt;
}	t_prg;

void	usage(void);
void	exit_msg(const char *message, unsigned char value);
void	julia(t_prg *p);
void	mandelbrot(t_prg *p);
void	burningship(t_prg *p);

#endif
