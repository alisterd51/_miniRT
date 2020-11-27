/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:55:07 by anclarma          #+#    #+#             */
/*   Updated: 2020/11/27 15:36:51 by antoine          ###   ########.fr       */
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
	if (res)
		printf("res: x_size = %d, y_size = %d\n", res->x_size, res->y_size);
}

void	print_amb_light(t_amb_light *amb_light)
{
	if (amb_light)
		printf("amb_light: ratio = %.1f, color = %hhu,%hhu,%hhu\n", amb_light->ratio, amb_light->color.r, amb_light->color.g, amb_light->color.b);
}

void	print_lst_cam(t_cam *cam)
{
	while (cam)
	{
		printf("cam: coord = %.1f,%.1f,%.1f", cam->coord.x, cam->coord.y, cam->coord.z);
		printf(", normal = %.1f,%.1f,%.1f", cam->normal.x, cam->normal.y, cam->normal.z);
		printf(", fov = %d", cam->fov);
		printf(", parameter = %s", cam->parameter);
		printf(", next = %p\n", cam->next);
		cam = cam->next;
	}
}

void	print_lst_light(t_light *light)
{
	while (light)
	{
		printf("light: coord = %.1f,%.1f,%.1f", light->coord.x, light->coord.y, light->coord.z);
		printf(", ratio = %.1f", light->ratio);
		printf(", color = %hhu,%hhu,%hhu", light->color.r, light->color.g, light->color.b);
		printf(", next = %p\n", light->next);
		light = light->next;
	}
}

void	print_lst_sphere(t_sphere *sphere)
{
	while (sphere)
	{
		printf("sphere: coord = %.1f,%.1f,%.1f", sphere->coord.x, sphere->coord.y, sphere->coord.z);
		printf(", diameter = %.1f", sphere->diameter);
		printf(", color = %hhu,%hhu,%hhu", sphere->color.r, sphere->color.g, sphere->color.b);
		printf(", parameter = %s", sphere->parameter);
		printf(", next = %p\n", sphere->next);
		sphere = sphere->next;
	}
}

void	print_lst_plane(t_plane *plane)
{
	while (plane)
	{
		printf("plane: coord = %.1f,%.1f,%.1f", plane->coord.x, plane->coord.y, plane->coord.z);
		printf(", normal = %.1f,%.1f,%.1f", plane->normal.x, plane->normal.y, plane->normal.z);
		printf(", color = %hhu,%hhu,%hhu", plane->color.r, plane->color.g, plane->color.b);
		printf(", next = %p\n", plane->next);
		plane = plane->next;
	}
}

void	print_lst_square(t_square *square)
{
	while (square)
	{
		printf("square: coord = %.1f,%.1f,%.1f", square->coord.x, square->coord.y, square->coord.z);
		printf(", normal = %.1f,%.1f,%.1f", square->normal.x, square->normal.y, square->normal.z);	
		printf(", side = %.1f", square->side);
		printf(", color = %hhu,%hhu,%hhu", square->color.r, square->color.g, square->color.b);
		printf(", next = %p\n", square->next);
		square = square->next;
	}
}

void	print_lst_cylinder(t_cylinder *cylinder)
{
	while (cylinder)
	{
		printf("cylinder: coord = %.1f,%.1f,%.1f", cylinder->coord.x, cylinder->coord.y, cylinder->coord.z);
		printf(", normal = %.1f,%.1f,%.1f", cylinder->normal.x, cylinder->normal.y, cylinder->normal.z);
		printf(", color = %hhu,%hhu,%hhu", cylinder->color.r, cylinder->color.g, cylinder->color.b);
		printf(", diameter = %.1f", cylinder->diameter);
		printf(", height = %.1f", cylinder->height);
		printf(", next = %p\n", cylinder->next);
		cylinder = cylinder->next;
	}
}

void	print_lst_triangle(t_triangle *triangle)
{
	while (triangle)
	{
		printf("triangle: coord1 = %.1f,%.1f,%.1f", triangle->coord1.x, triangle->coord1.y, triangle->coord1.z);
		printf("triangle: coord2 = %.1f,%.1f,%.1f", triangle->coord2.x, triangle->coord2.y, triangle->coord2.z);
		printf("triangle: coord3 = %.1f,%.1f,%.1f", triangle->coord3.x, triangle->coord3.y, triangle->coord3.z);
		printf(", color = %hhu,%hhu,%hhu", triangle->color.r, triangle->color.g, triangle->color.b);
		printf(", next = %p\n", triangle->next);
		triangle = triangle->next;
	}
}

void	print_lst_cone(t_cone *cone)
{
	while (cone)
	{
		printf("cone: coord = %.1f,%.1f,%.1f", cone->coord.x, cone->coord.y, cone->coord.z);
		printf(", normal = %.1f,%.1f,%.1f", cone->normal.x, cone->normal.y, cone->normal.z);
		printf(", diameter = %.1f", cone->diameter);
		printf(", height = %.1f", cone->height);
		printf(", color = %hhu,%hhu,%hhu", cone->color.r, cone->color.g, cone->color.b);
		printf(", next = %p\n", cone->next);
		cone = cone->next;
	}
}

void	print_obj(t_obj *obj)
{
	print_res(obj->res);
	print_amb_light(obj->amb_light);
	print_lst_cam(obj->lst_cam);
	print_lst_light(obj->lst_light);
	print_lst_sphere(obj->lst_sphere);
	print_lst_plane(obj->lst_plane);
	print_lst_square(obj->lst_square);
	print_lst_cylinder(obj->lst_cylinder);
	print_lst_triangle(obj->lst_triangle);
	print_lst_cone(obj->lst_cone);
}
