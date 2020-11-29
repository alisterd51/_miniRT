# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compil.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 00:48:11 by antoine           #+#    #+#              #
#    Updated: 2020/11/28 23:36:13 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang -Wall -Wextra -Werror -lm -fsanitize=address -g main.c lst_obj.c parsing.c res.c exit_err.c to_char.c read_line.c check_file.c amb_light.c lst_cam.c lst_light.c lst_sphere.c lst_plane.c lst_square.c lst_cylinder.c lst_triangle.c lst_cone.c rot_vector.c lst_cube.c vector1.c vector2.c vector3.c extremum.c lst_pyramid.c libft.a
