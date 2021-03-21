/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:12:00 by antoine           #+#    #+#             */
/*   Updated: 2021/03/21 16:11:03 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"
#include "vector.h"

void		add_end_lst_triangle(t_triangle *new_triangle, t_obj *obj)
{
	t_triangle	*tmp_triangle;

	if (!obj->lst_triangle)
		obj->lst_triangle = new_triangle;
	else
	{
		tmp_triangle = obj->lst_triangle;
		while (tmp_triangle->next)
			tmp_triangle = tmp_triangle->next;
		tmp_triangle->next = new_triangle;
	}
}

void		init_lst_triangle(char *line, t_obj *obj)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	if (!triangle)
		return (exit_errcode(MALLOC_ERROR));
	triangle->coord1 = read_line_to_vector(&line);
	if (triangle->coord1.x == DBL_MIN || triangle->coord1.y == DBL_MIN
			|| triangle->coord1.z == DBL_MIN)
		return (exit_errcode(TRIANGLE_ERROR_LINE));
	triangle->coord2 = read_line_to_vector(&line);
	if (triangle->coord2.x == DBL_MIN || triangle->coord2.y == DBL_MIN
			|| triangle->coord2.z == DBL_MIN)
		return (exit_errcode(TRIANGLE_ERROR_LINE));
	triangle->coord3 = read_line_to_vector(&line);
	if (triangle->coord3.x == DBL_MIN || triangle->coord3.y == DBL_MIN
			|| triangle->coord3.z == DBL_MIN)
		return (exit_errcode(TRIANGLE_ERROR_LINE));
	triangle->edge1 = sub_vector(triangle->coord2, triangle->coord1);
	triangle->edge2 = sub_vector(triangle->coord3, triangle->coord1);
	triangle->color = read_line_to_color(&line);
	triangle->next = NULL;
	if (*line || triangle->color.depth)
		return (exit_errcode(TRIANGLE_ERROR_LINE));
	add_end_lst_triangle(triangle, obj);
}

void		free_lst_triangle(t_obj *obj)
{
	t_triangle	*triangle;
	t_triangle	*next_triangle;

	triangle = obj->lst_triangle;
	while (triangle)
	{
		next_triangle = triangle->next;
		free(triangle);
		triangle = next_triangle;
	}
	obj->lst_triangle = NULL;
}

t_vector	triangle_albedo(t_triangle *lst_triangle, int id_triangle)
{
	while (id_triangle-- > 0)
		lst_triangle = lst_triangle->next;
	return (color_to_vector(lst_triangle->color));
}
