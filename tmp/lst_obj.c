/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:55:07 by anclarma          #+#    #+#             */
/*   Updated: 2020/10/19 15:25:34 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "lst_obj.h"

t_obj	*init_obj(void)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->lst_cam = NULL;
	obj->lst_light = NULL;
	obj->lst_sphere = NULL;
	obj->lst_plane = NULL;
	obj->lst_square = NULL;
	obj->lst_cylinder = NULL;
	obj->lst_triangle = NULL;
	obj->lst_cone = NULL;
	return (obj);
}

void	free_obj(t_obj *obj)
{
	free_lst_cam(obj->lst_cam);
	free_lst_light(obj->lst_light);
	free_lst_sphere(obj->lst_sphere);
	free_lst_plane(obj->lst_plane);
	free_lst_square(obj->lst_square);
	free_lst_cylinder(obj->lst_cylinder);
	free_lst_triangle(obj->lst_triangle);
	free_lst_cone(obj->lst_cone);
	free(obj);
}

//fonction de debug, a retirer avant le rendu
void	print_obj(t_obj *obj)
{
	printf("res: x_size = %d, y_size = %d\n", obj->res.x_size, obj->res.x_size);
}
