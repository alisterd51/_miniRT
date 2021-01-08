/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:13:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/08 16:52:57 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "intersect.h"

int		rt_inter_scene(t_check_scene *check)
{
	int		has_inter;

	has_inter = 0;
	check->min_t = 1e99;
	(check->obj_id)[0] = 0;
	(check->obj_id)[1] = 0;
	while (check->scene.lst_sphere)
	{
		has_inter += check_inter_sphere(check);
		check->scene.lst_sphere = check->scene.lst_sphere->next;
	}
	while (check->scene.lst_plane)
	{
		has_inter += check_inter_plane(check);
		check->scene.lst_plane = check->scene.lst_plane->next;
	}
	while (check->scene.lst_triangle)
	{
		has_inter += check_inter_triangle(check);
		check->scene.lst_triangle = check->scene.lst_triangle->next;
	}
	while (check->scene.lst_square)
    {
        has_inter += check_inter_square(check);
        check->scene.lst_square = check->scene.lst_square->next;
    }
	while (check->scene.lst_cylinder)
	{
		has_inter += check_inter_cylinder(check);
		check->scene.lst_cylinder = check->scene.lst_cylinder->next;
	}
	return (has_inter);
}
