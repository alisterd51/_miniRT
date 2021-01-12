/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:33:20 by antoine           #+#    #+#             */
/*   Updated: 2021/01/12 12:27:04 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"
#include "vector.h"

void	add_end_lst_cylinder(t_cylinder *new_cylinder, t_obj *obj)
{
	t_cylinder	*tmp_cylinder;

	if (!obj->lst_cylinder)
		obj->lst_cylinder = new_cylinder;
	else
	{
		tmp_cylinder = obj->lst_cylinder;
		while (tmp_cylinder->next)
			tmp_cylinder = tmp_cylinder->next;
		tmp_cylinder->next = new_cylinder;
	}
}

void	init_lst_cylinder(char *line, t_obj *obj)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (exit_errcode(MALLOC_ERROR));
	cylinder->coord = read_line_to_vector(&line);
	cylinder->normal = read_line_to_vector(&line);
	cylinder->diameter = read_line_to_double(&line);
	cylinder->radius2 = cylinder->diameter * cylinder->diameter / 4.0;
	cylinder->height = read_line_to_double(&line);
	cylinder->color = read_line_to_color(&line);
	cylinder->next = NULL;
	if (*line || cylinder->color.depth)
		return (exit_errcode(CYLINDER_ERROR_LINE));
	add_end_lst_cylinder(cylinder, obj);
}

void	free_lst_cylinder(t_obj *obj)
{
	t_cylinder	*cylinder;
	t_cylinder	*next_cylinder;

	cylinder = obj->lst_cylinder;
	while (cylinder)
	{
		next_cylinder = cylinder->next;
		free(cylinder);
		cylinder = next_cylinder;
	}
	obj->lst_cylinder = NULL;
}

t_vector    cylinder_albedo(t_cylinder *lst_cylinder, int id_cylinder)
{
	while (id_cylinder-- > 0)
		lst_cylinder = lst_cylinder->next;
	return (color_to_vector(lst_cylinder->color));
}
