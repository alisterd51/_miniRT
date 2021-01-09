/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   albedo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:52:28 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 11:32:30 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "lst_obj.h"

t_vector	obj_albedo(t_check *check)
{
	if (check->id_cat == 1)
		return (sphere_albedo(check->obj->lst_sphere, check->id_obj));
	else if (check->id_cat == 2)
		return (plane_albedo(check->obj->lst_plane, check->id_obj));
	else if (check->id_cat == 3)
		return (square_albedo(check->obj->lst_square, check->id_obj));
	else if (check->id_cat == 4)
		return (cylinder_albedo(check->obj->lst_cylinder, check->id_obj));
	else if (check->id_cat == 5)
		return (triangle_albedo(check->obj->lst_triangle, check->id_obj));
	else if (check->id_cat == 6)
		return (cone_albedo(check->obj->lst_cone, check->id_obj));
	return (init_vector(0, 0, 0));
}
