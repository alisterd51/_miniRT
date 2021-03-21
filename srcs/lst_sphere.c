/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:49:29 by antoine           #+#    #+#             */
/*   Updated: 2021/03/21 16:12:29 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"
#include "vector.h"

void		add_end_lst_sphere(t_sphere *new_sphere, t_obj *obj)
{
	t_sphere	*tmp_sphere;

	if (!obj->lst_sphere)
		obj->lst_sphere = new_sphere;
	else
	{
		tmp_sphere = obj->lst_sphere;
		while (tmp_sphere->next)
			tmp_sphere = tmp_sphere->next;
		tmp_sphere->next = new_sphere;
	}
}

void		init_lst_sphere(char *line, t_obj *obj)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (exit_errcode(MALLOC_ERROR));
	sphere->coord = read_line_to_vector(&line);
	if (sphere->coord.x == DBL_MIN || sphere->coord.y == DBL_MIN
			|| sphere->coord.z == DBL_MIN)
		return (exit_errcode(SPHERE_ERROR_LINE));
	sphere->diameter = read_line_to_double(&line);
	if (sphere->diameter == DBL_MIN)
		return (exit_errcode(SPHERE_ERROR_LINE));
	sphere->radius2 = sphere->diameter * sphere->diameter / 2.0;
	sphere->color = read_line_to_color(&line);
	if ((*line && !ft_isspace(*line)) || sphere->color.depth)
		return (exit_errcode(SPHERE_ERROR_LINE));
	sphere->parameter = read_line_to_string(&line);
	if (!sphere->parameter)
		return (exit_errcode(MALLOC_ERROR));
	sphere->next = NULL;
	add_end_lst_sphere(sphere, obj);
}

void		free_lst_sphere(t_obj *obj)
{
	t_sphere	*sphere;
	t_sphere	*next_sphere;

	sphere = obj->lst_sphere;
	while (sphere)
	{
		next_sphere = sphere->next;
		if (sphere->parameter)
			free(sphere->parameter);
		free(sphere);
		sphere = next_sphere;
	}
	obj->lst_sphere = NULL;
}

t_vector	sphere_albedo(t_sphere *lst_sphere, int id_sphere)
{
	while (id_sphere-- > 0)
		lst_sphere = lst_sphere->next;
	return (color_to_vector(lst_sphere->color));
}
