/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:25:07 by antoine           #+#    #+#             */
/*   Updated: 2020/11/23 15:12:28 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

static void	add_end_lst_plane(t_plane *new_plane, t_obj *obj)
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

	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		return (exit_errcode(MALLOC_ERROR));
	plane->coord = read_line_to_vector(&line);
	plane->normal = read_line_to_vector(&line);
	plane->color = read_line_to_color(&line);
	plane->next = NULL;
	if (*line || plane->color.depth)
		return (exit_errcode(LIGHT_ERROR_LINE));
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
