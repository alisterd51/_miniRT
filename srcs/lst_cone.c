/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:12:00 by antoine           #+#    #+#             */
/*   Updated: 2021/03/21 16:07:28 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"
#include "vector.h"

void		add_end_lst_cone(t_cone *new_cone, t_obj *obj)
{
	t_cone	*tmp_cone;

	if (!obj->lst_cone)
		obj->lst_cone = new_cone;
	else
	{
		tmp_cone = obj->lst_cone;
		while (tmp_cone->next)
			tmp_cone = tmp_cone->next;
		tmp_cone->next = new_cone;
	}
}

void		init_lst_cone(char *line, t_obj *obj)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		return (exit_errcode(MALLOC_ERROR));
	cone->coord = read_line_to_vector(&line);
	if (cone->coord.x == DBL_MIN || cone->coord.y == DBL_MIN
			|| cone->coord.z == DBL_MIN)
		return (exit_errcode(CONE_ERROR_LINE));
	cone->normal = read_line_to_vector(&line);
	if (cone->normal.x == DBL_MIN || cone->normal.y == DBL_MIN
			|| cone->normal.z == DBL_MIN)
		return (exit_errcode(CONE_ERROR_LINE));
	cone->diameter = read_line_to_double(&line);
	if (cone->diameter == DBL_MIN)
		return (exit_errcode(CONE_ERROR_LINE));
	cone->height = read_line_to_double(&line);
	if (cone->height == DBL_MIN)
		return (exit_errcode(CONE_ERROR_LINE));
	cone->color = read_line_to_color(&line);
	cone->next = NULL;
	if (*line || cone->color.depth)
		return (exit_errcode(CONE_ERROR_LINE));
	add_end_lst_cone(cone, obj);
}

void		free_lst_cone(t_obj *obj)
{
	t_cone	*cone;
	t_cone	*next_cone;

	cone = obj->lst_cone;
	while (cone)
	{
		next_cone = cone->next;
		free(cone);
		cone = next_cone;
	}
	obj->lst_cone = NULL;
}

t_vector	cone_albedo(t_cone *lst_cone, int id_cone)
{
	while (id_cone-- > 0)
		lst_cone = lst_cone->next;
	return (color_to_vector(lst_cone->color));
}
