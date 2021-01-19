# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 23:58:07 by anclarma          #+#    #+#              #
#    Updated: 2021/01/15 11:16:49 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
FLAGS		= -Wall -Wextra -Werror \
			  -O3
MLX_LINUX	= -lm -lmlx -lXext -lX11 -lpthread
MLX_MAC		= -lmlx -framework OpenGL -framework AppKit
INCLUDES	= -I /usr/local/include \
			  -I ./libft \
			  -I ./includes
LIBS		= -L /usr/local/lib
PATH_SRCS	= ./srcs/
C_FILES		= main.c \
			  initpixel.c \
			  input.c \
			  render.c \
			  vector1.c \
			  vector2.c \
			  vector3.c \
			  extremum.c \
			  scenescan.c \
			  getcolor.c \
			  this_obj_is.c \
			  albedo.c \
			  intersect1.c \
			  intersect2.c \
			  intersect3.c \
			  intersect4.c \
			  intersect5.c \
			  intersect6.c \
			  parser.c \
			  init_obj1.c \
			  init_obj2.c \
			  init_obj3.c \
			  init_obj4.c \
			  screenshot.c \
			  ft_tobmp.c
SRCS		= $(addprefix srcs/,$(C_FILES)) \
			  ./libft/libft.a
OBJS		= $(SRCS:.c=.o)

TMP_C		= main.c lst_obj.c parsing.c res.c exit_err.c to_char.c read_line.c check_file.c amb_light.c lst_cam.c lst_light.c lst_sphere.c lst_plane.c lst_square.c lst_cylinder.c lst_triangle.c lst_cone.c rot_vector.c lst_cube.c vector1.c vector2.c vector3.c extremum.c lst_pyramid.c input.c render.c scenescan.c getcolor.c check.c this_obj_is.c albedo.c intersect.c inter_sphere.c inter_plane.c inter_square.c inter_cylinder.c inter_triangle.c inter_cone.c screenshot.c to_bmp.c add_amb_light.c tmp_lst_obj.c
TMP_SRCS	= $(addprefix tmp_srcs/,$(TMP_C)) \
			  ./libft/libft.a

.c.o:
	@clang $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	sub-make $(OBJS)
	@clang $(FLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX_MAC) -o $(NAME)

sub-make:
	@make -C libft all

install:
	git clone https://github.com/42Paris/minilibx-linux.git
	cd minilibx-linux
	./configure
	sudo cp libmlx.a /usr/local/lib/.
	sudo cp libmlx_Linux.a /usr/local/lib/.
	sudo cp mlx.h /usr/local/include/.
	sudo mkdir /usr/local/man/man3
	sudo cp man/man3/mlx*.1 /usr/local/man/man3/.
	cd ..
	rm -rf minilibx-linux

clean:
	@make -C libft clean
	@rm -f $(OBJS)

fclean:
	@make -C libft fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re:			fclean all

debug:		sub-make
	clang -Wall -Wextra -Werror -lm -Ofast  -I /usr/local/include -I ./libft -I ./tmp_includes $(TMP_SRCS) -L /usr/local/lib $(MLX_LINUX) -o test_parseur.out

.PHONY:	all	$(NAME) clean fclean re install debug
