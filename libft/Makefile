# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 23:29:46 by anclarma          #+#    #+#              #
#    Updated: 2021/02/21 11:36:54 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
FLAGS		= -Wall -Wextra -Werror -O3
SRCS		= ft_printf.c \
		  ft_ifforest.c \
		  ft_out1.c \
		  ft_out2.c \
		  ft_out3.c \
		  ft_padding.c \
		  ft_convert.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_strnlen.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_isspace.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_atof.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c\
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_itoa_base.c \
		  ft_utoa_base.c \
		  ft_utoa.c \
		  ft_strmapi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  get_next_line.c
OBJS		= ${SRCS:.c=.o}

.c.o:
	@(cc ${FLAGS} -c $< -o ${<:.c=.o})
	@printf "\033[32;1mcompil %s: %20.20s\033[0m\r" $(NAME) $<

all:		$(NAME)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean:		clean
	@rm -f $(NAME)

re:			fclean clean all
.SILENT:
