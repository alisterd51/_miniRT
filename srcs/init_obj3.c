/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:40:45 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/13 17:31:09 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "init_obj.h"
#include "libft.h"
#include <stdlib.h>

int	init_sphere(char *line, t_obj *obj)
{
	t_sphere		*new_sphere;
	t_sphere		*ptr_tmp;
	int				num_sphere;

	if (!(new_sphere = malloc(sizeof(t_sphere))))
		return (1);
	new_sphere->id = 0;	// remplir avec le num de la cam [0, 1, ...]
	new_sphere->c = read_vec(&line);
	new_sphere->radius = read_float(&line);
	new_sphere->color = read_color(&line);
	new_sphere->mirror = read_option(&line);
	new_sphere->transp = read_option2(&line);
	new_sphere->next = NULL;
	num_sphere = 0;
	if (obj->lst_sphere == NULL)
		obj->lst_sphere = new_sphere;
	else
	{
		num_sphere++;
		ptr_tmp = obj->lst_sphere;
		while (ptr_tmp->next != NULL)
		{
			num_sphere++;
			ptr_tmp = ptr_tmp->next;
		}
		new_sphere->id = num_sphere;
		ptr_tmp->next = new_sphere;
	}
	return (0);
}

int	init_plane(char *line, t_obj *obj)
{
	t_plane		*new_plane;
	t_plane		*ptr_tmp;

	if (!(new_plane = malloc(sizeof(t_plane))))
		return (1);
	new_plane->id = 0;	// remplir avec le num de la cam [0, 1, ...]
	new_plane->c = read_vec(&line);
	new_plane->o = read_vec(&line);
	new_plane->color = read_color(&line);
	new_plane->next = NULL;
	if (obj->lst_plane == NULL)
		obj->lst_plane = new_plane;
	else
	{
		new_plane->id++;
		ptr_tmp = obj->lst_plane;
		while (ptr_tmp->next != NULL)
		{
			new_plane->id++;
			ptr_tmp = ptr_tmp->next;
		}
		ptr_tmp->next = new_plane;
	}
	return (0);
}

int	init_square(char *line, t_obj *obj)
{
	t_square	*new_square;
	t_square	*ptr_tmp;

	if (!(new_square = malloc(sizeof(t_square))))
		return (1);
	new_square->id = 0;	// remplir avec le num de la cam [0, 1, ...]
	new_square->c = read_vec(&line);
	new_square->o = read_vec(&line);
	new_square->height = read_float(&line);
	new_square->color = read_color(&line);
	new_square->next = NULL;
	if (obj->lst_square == NULL)
		obj->lst_square = new_square;
	else
	{
		new_square->id++;
		ptr_tmp = obj->lst_square;
		while (ptr_tmp->next != NULL)
		{
			new_square->id++;
			ptr_tmp = ptr_tmp->next;
		}
		ptr_tmp->next = new_square;
	}
	return (0);
}

int	init_cylinder(char *line, t_obj *obj)
{
	t_cylinder	*new_cylinder;
	t_cylinder	*ptr_tmp;

	if (!(new_cylinder = malloc(sizeof(t_cylinder))))
		return (1);
	new_cylinder->id = 0;	// remplir avec le num de la cam [0, 1, ...]
	new_cylinder->c = read_vec(&line);
	new_cylinder->o = read_vec(&line);
	new_cylinder->radius = read_float(&line);
	new_cylinder->height = read_float(&line);
	new_cylinder->color = read_color(&line);
	new_cylinder->next = NULL;
	if (obj->lst_cylinder == NULL)
		obj->lst_cylinder = new_cylinder;
	else
	{
		new_cylinder->id++;
		ptr_tmp = obj->lst_cylinder;
		while (ptr_tmp->next != NULL)
		{
			new_cylinder->id++;
			ptr_tmp = ptr_tmp->next;
		}
		ptr_tmp->next = new_cylinder;
	}
	return (0);
}

int	init_triangle(char *line, t_obj *obj)
{
	t_triangle	*new_triangle;
	t_triangle	*ptr_tmp;

	if (!(new_triangle = malloc(sizeof(t_triangle))))
		return (1);
	new_triangle->id = 0;	// remplir avec le num de la cam [0, 1, ...]
	new_triangle->p1 = read_vec(&line);
	new_triangle->p2 = read_vec(&line);
	new_triangle->p3 = read_vec(&line);
	new_triangle->color = read_color(&line);
	new_triangle->next = NULL;
	if (obj->lst_triangle == NULL)
		obj->lst_triangle = new_triangle;
	else
	{
		new_triangle->id++;
			ptr_tmp = obj->lst_triangle;
		while (ptr_tmp->next != NULL)
		{
			new_triangle->id++;
			ptr_tmp = ptr_tmp->next;
		}
		ptr_tmp->next = new_triangle;
	}
	return (0);
}
