/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 00:06:15 by antoine           #+#    #+#             */
/*   Updated: 2020/11/27 00:33:40 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "lst_obj.h"
#include "rot_vector.h"

/*
** manque la generation des 4 triangles
*/
void	init_lst_pyramid(char *line, t_obj *obj)
{
	t_square	*base;
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
}
