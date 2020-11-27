/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:55:07 by anclarma          #+#    #+#             */
/*   Updated: 2020/11/27 01:12:05 by antoine          ###   ########.fr       */
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
	obj->res = NULL;
	obj->amb_light = NULL;
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

void	free_obj(t_obj **obj)
{
	if (!*obj)
		return ;
	free_res(*obj);
	free_amb_light(*obj);
	free_lst_cam(*obj);
	free_lst_light(*obj);
	free_lst_sphere(*obj);
	free_lst_plane(*obj);
	free_lst_square(*obj);
	free_lst_cylinder(*obj);
	free_lst_triangle(*obj);
	free_lst_cone(*obj);
	free(*obj);
	*obj = NULL;
}

//fonction de debug, a retirer avant le rendu
void	print_res(t_res *res)
{
	printf("res: x_size = %d, y_size = %d\n", res->x_size, obj->res->x_size);
}

void	print_obj(t_obj *obj)
{
	print_res(obj->res);
	print_amb_light(obj->amb_light);
	print_lst_cam(obj->lst_cam);
	print_lst_light(obj->lst_light;
	print_lst_sphere(obj->lst_sphere);
	print_lst_plane(obj->lst_plane);
	print_lst_square(obj->lst_square);
	print_lst_cylinder(obj->lst_cylinder);
	print_lst_triangle(obj->lst_triangle);
	print_lst_cone(obj->lst_cone);
}
