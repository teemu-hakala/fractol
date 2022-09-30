/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:14:24 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 10:39:33 by thakala          ###   ########.fr       */
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
# define TWO_POW_EIGHT 256
# define INITIAL_ITERATIONS 100
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_palette
{
	PALETTE_MONO_BLU = 0,
	PALETTE_MONO_GRN = 1,
	PALETTE_MONO_RED = 2,
	PALETTE_GRAYSCALE
}	t_pltt;

typedef enum e_rgb_shifts
{
	RGB_RED = 16,
	RGB_GRN = 8,
	RGB_BLU = 0
}	t_rgb;

typedef struct s_point
{
	int		row;
	int		col;
}	t_pt;

typedef struct s_long_double_coordinate
{
	long double	row;
	long double	col;
}	t_ldbl_pt;

typedef struct s_ldbl_scale_pt
{
	long double	ver;
	long double	hor;
	t_bool		calculated;
}	t_scale_pt;

typedef struct s_fractol		t_fct;
typedef struct s_minilibx		t_mlx;
typedef struct s_mouse			t_mse;
typedef struct s_keyboard		t_key;
typedef struct s_user_inputs	t_ipt;
typedef struct s_program		t_prg;
typedef void					(*t_ftype)(struct s_program *);

struct s_program
{
	t_fct	*fct;
	t_mlx	*mlx;
	t_ipt	*ipt;
};

struct s_fractol
{
	t_ftype		type;
	uint64_t	iter;
	uint64_t	zoom; //perhaps a floating-point type instead?
	t_pltt		pltt;
};

typedef struct s_minilibx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

struct s_minilibx
{
	void	*mlx;
	void	*win;
	t_img	img;
};

struct s_mouse
{
	t_pt	prev;
	t_pt	curr;
	t_pt	diff;
	t_bool	isdown;
};

struct s_keyboard
{
	t_bool	cmd_toggled;
};

struct s_user_inputs
{
	t_mse	mse;
	t_key	key;
};

void		usage(void);
void		exit_msg(const char *message, unsigned char value);
void		julia(t_prg *p);
void		mandelbrot(t_prg *p);
void		burningship(t_prg *p);
long double	eight_bit_color_graph_sqrt_x_flip(long double iter_perc);
int			palette(t_prg *pr, uint64_t iteration);
t_prg		*draw(t_prg *p);
void		pixelput(t_img *img, int x, int y, int colour);
int			loop(t_prg *p);
void		fetch_new_image(t_mlx *m);
t_prg		*init(t_prg *p);
void		init_mlx(t_mlx *m);
void		init_win(t_mlx *m);
void		init_img(t_mlx *m);
void		init_fct(t_fct *f);
void		init_ipt(t_ipt *i);
int			mandelbrot_plot(t_prg *pr, t_ldbl_pt *p0);
void		mandelbrot_scales(t_ldbl_pt *p0, t_pt px);

#endif
