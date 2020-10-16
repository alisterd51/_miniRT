# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 23:58:07 by anclarma          #+#    #+#              #
#    Updated: 2020/10/16 15:25:47 by anclarma         ###   ########.fr        #
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

.c.o:
	gcc $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	sub-make $(OBJS)
	gcc $(FLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX_MAC) -o $(NAME)

sub-make:
	make -C libft all

install:
	git clone https://github.com/42Paris/minilibx-linux.git
	./minilibx-linux/configure
	sudo cp minilibx-linux/libmlx.a /usr/local/lib/.
	sudo cp minilibx-linux/libmlx_Linux.a /usr/local/lib/.
	sudo cp minilibx-linux/mlx.h /usr/local/include/.
	sudo mkdir /usr/local/man/man3
	sudo cp minilibx-linux/man/man3/mlx*.1 /usr/local/man/man3/.
	rm -rf minilibx-linux

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:
	make -C libft fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re:			fclean all

.PHONY:	all	$(NAME) clean fclean re install
