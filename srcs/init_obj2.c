/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:39:48 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/13 17:30:32 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "init_obj.h"
#include "libft.h"
#include <stdlib.h>

void	init_obj(t_obj *obj)
{
	obj->resolution = NULL;
	obj->amblight = NULL;
	obj->lst_cam = NULL;
	obj->lst_light = NULL;
	obj->lst_sphere = NULL;
	obj->lst_plane = NULL;
	obj->lst_square = NULL;
	obj->lst_cylinder = NULL;
	obj->lst_triangle = NULL;
}

int		init_res(char *line, t_obj *obj)
{
	if (!(obj->resolution = malloc(sizeof(t_res))))
		return (1);
	obj->resolution->x_size = read_int(&line);
	obj->resolution->y_size = read_int(&line);
	return (0);
}

int		init_amblight(char *line, t_obj *obj)
{
	if (!(obj->amblight = malloc(sizeof(t_amblight))))
		return (1);
	obj->amblight->ratio = read_float(&line);
	obj->amblight->color = read_color(&line);
	return (0);
}

int		init_cam(char *line, t_obj *obj)
{
	t_camera	*new_cam;
	t_camera	*ptr_tmp;

	if (!(new_cam = malloc(sizeof(t_camera))))
		return (1);
	new_cam->id = 0;	// remplir avec le num de la cam [0, 1, ...]
	new_cam->c = read_vec(&line);
	new_cam->vec = read_vec(&line);
	new_cam->fov = read_int(&line);
	new_cam->next = NULL;
	if (obj->lst_cam == NULL)
		obj->lst_cam = new_cam;
	else
	{
		ptr_tmp = obj->lst_cam;
		while (ptr_tmp->next != NULL)
			ptr_tmp = ptr_tmp->next;
		ptr_tmp->next = new_cam;
	}
	return (0);
}

int		init_light(char *line, t_obj *obj)
{
	t_light		*new_light;
	t_light		*ptr_tmp;

	if (!(new_light = malloc(sizeof(t_light))))
		return (1);
	new_light->id = 0;	// remplir avec le num de la cam [0, 1, ...]
	new_light->c = read_vec(&line);
	new_light->ratio = read_float(&line);
	new_light->color = read_color(&line);
	new_light->next = NULL;

	if (obj->lst_light == NULL)
		obj->lst_light = new_light;
	else
	{
		ptr_tmp = obj->lst_light;
		while (ptr_tmp->next != NULL)
			ptr_tmp = ptr_tmp->next;
		ptr_tmp->next = new_light;
	}
	return (0);
}
