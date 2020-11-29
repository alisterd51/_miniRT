/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:06:15 by antoine           #+#    #+#             */
/*   Updated: 2020/11/28 23:31:52 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "lst_obj.h"
#include "vector.h"
#include "rot_vector.h"

/*
** manque la generation des 4 triangles
*/
void	init_lst_pyramid(char *line, t_obj *obj)
{
	t_square	*base;
	t_triangle	*triangle;
	double		height;

	if (!(base = (t_square *)malloc(sizeof(t_square))))
		return (exit_errcode(MALLOC_ERROR));
	base->coord = read_line_to_vector(&line);
	base->normal = read_line_to_vector(&line);
	base->side = read_line_to_double(&line);
	height = read_line_to_double(&line);
	base->color = read_line_to_color(&line);
	base->next = NULL;
	if (*line || base->color.depth)
		return (exit_errcode(PYRAMID_ERROR_LINE));
	add_end_lst_square(base, obj);
	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return (exit_errcode(MALLOC_ERROR));
	triangle->coord1 = add_vector(base->coord, mult_vector(height, base->normal));
	t_vector vec1 = rot_vector(init_vector(M_PI / 2.0, M_PI / 2.0, 0.0), base->normal);
	t_vector coord1 = add_vector(base->coord, mult_vector(base->side / 2.0, vec1));
	t_vector vec2 = rot_vector(init_vector(0.0, M_PI / 2.0, 0.0), vec1);
	t_vector vec3 = rot_vector(init_vector(0.0, M_PI, 0.0), vec2);
	triangle->coord2 = add_vector(coord1, mult_vector(base->side / 2.0, vec2));
	triangle->coord3 = add_vector(coord1, mult_vector(base->side / 2.0, vec3));
	triangle->color = base->color;
	triangle->next = NULL;
	add_end_lst_triangle(triangle, obj);
}
