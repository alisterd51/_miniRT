/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:12:00 by antoine           #+#    #+#             */
/*   Updated: 2020/11/23 18:51:54 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

void	add_end_lst_cone(t_cone *new_cone, t_obj *obj)
{
	t_cone    *tmp_cone;

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
	t_cone    *cone;

	if (!(cone = (t_cone *)malloc(sizeof(t_cone))))
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
	t_cone    *cone;
	t_cone    *next_cone;

	cone = obj->lst_cone;
	while (cone)
	{
		next_cone = cone->next;
		free(cone);
		cone = next_cone;
	}
	obj->lst_cone = NULL;
}
