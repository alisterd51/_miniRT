# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compil.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 00:48:11 by antoine           #+#    #+#              #
#    Updated: 2020/11/23 18:57:10 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang -Wall -Wextra -Werror main.c lst_obj.c parsing.c res.c exit_err.c to_char.c read_line.c check_file.c amb_light.c lst_cam.c lst_light.c lst_sphere.c lst_plane.c lst_square.c lst_cylinder.c lst_triangle.c lst_cone.c libft.a
