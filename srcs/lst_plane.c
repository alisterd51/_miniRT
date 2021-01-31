/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:25:07 by antoine           #+#    #+#             */
/*   Updated: 2021/01/31 14:19:16 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"
#include "vector.h"

void		add_end_lst_plane(t_plane *new_plane, t_obj *obj)
{
	t_plane	*tmp_plane;

	if (!obj->lst_plane)
		obj->lst_plane = new_plane;
	else
	{
		tmp_plane = obj->lst_plane;
		while (tmp_plane->next)
			tmp_plane = tmp_plane->next;
		tmp_plane->next = new_plane;
	}
}

void		init_lst_plane(char *line, t_obj *obj)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (exit_errcode(MALLOC_ERROR));
	plane->coord = read_line_to_vector(&line);
	plane->normal = read_line_to_vector(&line);
	plane->color = read_line_to_color(&line);
	plane->next = NULL;
	if (*line || plane->color.depth)
		return (exit_errcode(PLANE_ERROR_LINE));
	add_end_lst_plane(plane, obj);
}

void		free_lst_plane(t_obj *obj)
{
	t_plane	*plane;
	t_plane	*next_plane;

	plane = obj->lst_plane;
	while (plane)
	{
		next_plane = plane->next;
		free(plane);
		plane = next_plane;
	}
	obj->lst_plane = NULL;
}

t_vector	plane_albedo(t_plane *lst_plane, int id_plane)
{
	while (id_plane-- > 0)
		lst_plane = lst_plane->next;
	return (color_to_vector(lst_plane->color));
}
