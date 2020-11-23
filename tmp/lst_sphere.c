/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:49:29 by antoine           #+#    #+#             */
/*   Updated: 2020/11/23 14:41:08 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

static void	add_end_lst_sphere(t_sphere *new_sphere, t_obj *obj)
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

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (exit_errcode(MALLOC_ERROR));
	sphere->coord = read_line_to_vector(&line);
	sphere->diameter = read_line_to_double(&line);
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
