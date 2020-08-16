# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 23:58:07 by anclarma          #+#    #+#              #
#    Updated: 2020/08/15 21:54:19 by anclarma         ###   ########.fr        #
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
SRCS		= $(PATH_SRCS)main.c \
			  $(PATH_SRCS)initpixel.c \
			  $(PATH_SRCS)input.c \
			  $(PATH_SRCS)render.c \
			  $(PATH_SRCS)vector1.c \
			  $(PATH_SRCS)vector2.c \
			  $(PATH_SRCS)vector3.c \
			  $(PATH_SRCS)extremum.c \
			  $(PATH_SRCS)scenescan.c \
			  $(PATH_SRCS)getcolor.c \
			  $(PATH_SRCS)this_obj_is.c \
			  $(PATH_SRCS)albedo.c \
			  $(PATH_SRCS)intersect1.c \
			  $(PATH_SRCS)intersect2.c \
			  $(PATH_SRCS)intersect3.c \
			  $(PATH_SRCS)intersect4.c \
			  $(PATH_SRCS)intersect5.c \
			  $(PATH_SRCS)intersect6.c \
			  $(PATH_SRCS)parser.c \
			  $(PATH_SRCS)init_obj1.c \
			  $(PATH_SRCS)init_obj3.c \
			  $(PATH_SRCS)init_obj2.c \
			  $(PATH_SRCS)screenshot.c \
			  ./libft/libft.a
OBJS		= $(SRCS:.c=.o)

.c.o:
	gcc $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	sub-make $(OBJS)
	gcc $(FLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX_MAC) -o $(NAME)

sub-make:
	make -C libft all

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:
	make -C libft fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re:			fclean all

.PHONY:	all	$(NAME) clean fceab re
