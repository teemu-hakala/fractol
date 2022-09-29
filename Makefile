# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 10:44:14 by thakala           #+#    #+#              #
#    Updated: 2022/09/29 16:40:44 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = \
	fractol \
	usage \
	loop \
	draw \
	image \
	init \
	init_help \
	fractals \
	fractal_julia \
	fractal_mandelbrot \
	fractal_burningship \
	scale \
	palette \
	color_graphs \
	pixelput \
	exit

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

DIRS = $(SRCS_DIR) $(OBJS_DIR)

INCS = -I includes/ -I libft/
HDRS = libft/libft.h includes/fractol.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MATH = -lm
MLX = -lmlx -framework OpenGL -framework AppKit

.PHONY: all
all: $(NAME)

$(NAME): .prerequisites libft/libft.a $(OBJS)
	touch .prerequisites
	$(CC) $(CFLAGS) $(INCS) $(MATH) $(MLX) libft/libft.a $(OBJS) -o $@

$(OBJS): $(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

.prerequisites: libft/libft.a $(DIRS) $(HDRS) $(SRCS)

libft/libft.a:
	make -C libft/

$(DIRS):
	mkdir -p $@

$(HDRS):
	touch $@

$(SRCS):
	touch $@

.PHONY: clean
clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

.PHONY: fclean
fclean:
	/bin/rm -f $(NAME) .prerequisites
	/bin/rm -rf $(OBJS_DIR)/
	make -C libft/ fclean

.PHONY: re
re: fclean all
