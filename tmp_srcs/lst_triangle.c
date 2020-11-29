/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:12:00 by antoine           #+#    #+#             */
/*   Updated: 2020/11/23 18:56:37 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

void	add_end_lst_triangle(t_triangle *new_triangle, t_obj *obj)
{
	t_triangle    *tmp_triangle;

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

void	init_lst_triangle(char *line, t_obj *obj)
{
	t_triangle    *triangle;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return (exit_errcode(MALLOC_ERROR));
	triangle->coord1 = read_line_to_vector(&line);
	triangle->coord2 = read_line_to_vector(&line);
	triangle->coord3 = read_line_to_vector(&line);
	triangle->color = read_line_to_color(&line);
	triangle->next = NULL;
	if (*line || triangle->color.depth)
		return (exit_errcode(TRIANGLE_ERROR_LINE));
	add_end_lst_triangle(triangle, obj);
}

void	free_lst_triangle(t_obj *obj)
{
	t_triangle    *triangle;
	t_triangle    *next_triangle;

	triangle = obj->lst_triangle;
	while (triangle)
	{
		next_triangle = triangle->next;
		free(triangle);
		triangle = next_triangle;
	}
	obj->lst_triangle = NULL;
}
