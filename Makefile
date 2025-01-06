# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 23:58:07 by anclarma          #+#    #+#              #
#    Updated: 2021/03/25 11:14:42 by pompier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -O3 -flto -ffast-math -march=native -pipe
MLX_LINUX	= -L ./minilibx-linux \
			  -I ./minilibx-linux \
			  -lm -lmlx -lXext -lX11 -lpthread
MLX_MAC		= -L ./minilibx-mac \
			  -I ./minilibx-mac \
			  -lmlx -framework OpenGL -framework AppKit
INCLUDES	= -I ./libft \
			  -I ./includes
LIB_LIBFT	= -L ./libft \
			  -lft
C_FILES		= main.c \
			  lst_obj.c \
			  parsing.c \
			  res.c \
			  exit_err.c \
			  to_char.c \
			  read_line.c \
			  check_file.c \
			  amb_light.c \
			  lst_cam.c \
			  lst_light.c \
			  lst_sphere.c \
			  lst_plane.c \
			  lst_square.c \
			  lst_cylinder.c \
			  lst_triangle.c \
			  lst_cone.c \
			  rot_vector.c \
			  lst_cube.c \
			  vector1.c \
			  vector2.c \
			  vector3.c \
			  extremum.c \
			  input.c \
			  render.c \
			  scenescan.c \
			  getcolor.c \
			  check.c \
			  this_obj_is.c \
			  albedo.c \
			  intersect.c \
			  inter_sphere.c \
			  inter_plane.c \
			  inter_square.c \
			  inter_cylinder.c \
			  inter_triangle.c \
			  inter_cone.c \
			  screenshot.c \
			  to_bmp.c \
			  add_amb_light.c \
			  secure_atoi.c \
			  init_mlx.c \
			  exit_hook.c \
			  movement.c
SRCS		= $(addprefix srcs/,$(C_FILES))
OBJS		= $(SRCS:.c=.o)
UNAME		:= $(shell uname)

ifeq ($(UNAME),Darwin)
    MLX = $(MLX_MAC)
    MACRO = -D MACOS -D NB_THREADS=$(shell sysctl -n hw.ncpu)
    PATH_MLX = minilibx-mac
endif
ifeq ($(UNAME),Linux)
    MLX = $(MLX_LINUX)
    MACRO = -D LINUX -D NB_THREADS=$(shell nproc --all)
    PATH_MLX = minilibx-linux
endif

INCLUDES += -I ./$(PATH_MLX)

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) $(MACRO) -c $< -o $(<:.c=.o)

all:		$(NAME)

bonus:		$(NAME)

$(NAME):	$(PATH_MLX)/libmlx.a libft/libft.a $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB_LIBFT) $(MLX) $(MACRO) -o $(NAME)

$(PATH_MLX)/libmlx.a:
	make -C $(PATH_MLX) all

libft/libft.a:
	make -C libft all --jobs

clean:
	make -C libft clean --jobs
	make -C $(PATH_MLX) clean --jobs
	rm -f $(OBJS)
	rm -rf $(NAME).dSYM

fclean: clean
	make -C libft fclean --jobs
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
