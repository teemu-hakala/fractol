/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:14:24 by thakala           #+#    #+#             */
/*   Updated: 2022/09/30 14:45:15 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define STR_JULIA "julia"
# define STR_MANDELBROT "mandelbrot"
# define STR_BURNINGSHIP "burningship"
# define WIN_WIDTH 1821
# define WIN_HEIGHT 1024
# define WIN_NAME "thakala's fract'ol"
# define ERR_NULL_MLX "GOT NULL: p->mlx.mlx = mlx_init();\n"
# define ERR_NULL_WIN "GOT NULL: p->mlx.win = mlx_new_window();\n"
# define TWO_POW_EIGHT 256
# define INITIAL_ITERATIONS 10//127
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

enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_key
{
	KEY_C_OLOUR = 8,
	KEY_P_ROJECTION = 35,
	KEY_ESC = 53,
	KEY_L_CMD = 259,
	KEY_R_CMD = 260
};

enum e_mouse
{
	MOVE = 0,
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_DN = 4,
	SCROLL_UP = 5
};

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
typedef int						(*t_hndlr)(struct s_program *, t_pt *);


struct s_program
{
	t_fct	*fct;
	t_mlx	*mlx;
	t_ipt	*ipt;
};

struct s_fractol
{
	t_ftype		type;
	long double	iter;
	long double	zoom;
	t_pltt		pltt;
	t_ldbl_pt	constant;
	t_pt		center;
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
	t_bool	refresh;
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

void			usage(void);
void			exit_msg(const char *message, unsigned char value);
void			julia(t_prg *p);
void			mandelbrot(t_prg *p);
void			burningship(t_prg *p);
long double		eight_bit_color_graph_sqrt_x_flip(long double iter_perc);
unsigned int	palette(t_prg *pr, long double iteration);
t_prg			*draw(t_prg *p);
void			pixelput(t_img *img, int x, int y, int colour);
int				loop(t_prg *p);
void			fetch_new_image(t_mlx *m);
t_prg			*init(t_prg *p);
void			init_mlx(t_mlx *m);
void			init_win(t_mlx *m);
void			init_img(t_mlx *m);
void			init_fct(t_fct *f);
void			init_ipt(t_ipt *i);
unsigned int	mandelbrot_plot(t_prg *pr, t_ldbl_pt *p0);
void			mandelbrot_scales(t_prg *pr, t_ldbl_pt *p0, t_pt px);
unsigned int	burningship_plot(t_prg *pr, t_ldbl_pt *p0);
void			burningship_scales(t_ldbl_pt *p0, t_pt px);
long double		abs_ldbl(long double ldbl);
unsigned int	julia_plot(t_prg *pr, t_ldbl_pt *p0);
void			julia_scales(t_ldbl_pt *p0, t_pt px);
int				vary_julia_constant(t_prg *p);
int				mouse_handler_down(int btn, int x, int y, t_prg *p);
void			hooks(t_prg *p);
void			mouse_register_click_down(int btn, int x, int y, t_prg *p);
void			mouse_register_click_up(int btn, int x, int y, t_prg *p);
int				mouse_handler_move(int x, int y, t_prg *p);
int				mouse_handler_up(int btn, int x, int y, t_prg *p);
void			pan(t_prg *p);

#endif
