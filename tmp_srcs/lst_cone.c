/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:12:00 by antoine           #+#    #+#             */
/*   Updated: 2021/01/09 13:05:24 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"
#include "vector.h"

void	add_end_lst_cone(t_cone *new_cone, t_obj *obj)
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

void	init_lst_cone(char *line, t_obj *obj)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		return (exit_errcode(MALLOC_ERROR));
	cone->coord = read_line_to_vector(&line);
	cone->normal = read_line_to_vector(&line);
	cone->diameter = read_line_to_double(&line);
	cone->height = read_line_to_double(&line);
	cone->color = read_line_to_color(&line);
	cone->next = NULL;
	if (*line || cone->color.depth)
		return (exit_errcode(CONE_ERROR_LINE));
	add_end_lst_cone(cone, obj);
}

void	free_lst_cone(t_obj *obj)
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
