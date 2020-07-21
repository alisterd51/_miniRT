/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   albedo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:05:03 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/21 15:20:26 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

t_vector	sphere_albedo(t_obj s, int sphere_id)
{
	t_sphere	*s_ptr;

	s_ptr = s.lst_sphere;
	while (s_ptr)
	{
		if (s_ptr->id == sphere_id)
			return (int_to_vector(s_ptr->color));
		s_ptr = s_ptr->next;
	}
	return (init_vector(0.0, 0.0, 0.0));
}

t_vector	triangle_albedo(t_obj s, int triangle_id)
{
	t_triangle	*tr_ptr;

	tr_ptr = s.lst_triangle;
	while (tr_ptr)
	{
		if (tr_ptr->id == triangle_id)
			return (int_to_vector(tr_ptr->color));
		tr_ptr = tr_ptr->next;
	}
	return (init_vector(0.0, 0.0, 0.0));
}

t_vector	plane_albedo(t_obj s, int plane_id)
{
	t_plane		*pl_ptr;

	pl_ptr = s.lst_plane;
	while (pl_ptr)
	{
		if (pl_ptr->id == plane_id)
			return (int_to_vector(pl_ptr->color));
		pl_ptr = pl_ptr->next;
	}
	return (init_vector(0.0, 0.0, 0.0));
}

t_vector	cylinder_albedo(t_obj s, int cylinder_id)
{
	t_cylinder	*cy_ptr;

	cy_ptr = s.lst_cylinder;
	while (cy_ptr)
	{
		if (cy_ptr->id == cylinder_id)
			return (int_to_vector(cy_ptr->color));
		cy_ptr = cy_ptr->next;
	}
	return (init_vector(0.0, 0.0, 0.0));
}

t_vector	square_albedo(t_obj s, int square_id)
{
	t_square	*sq_ptr;

    sq_ptr = s.lst_square;
    while (sq_ptr)
    {
        if (sq_ptr->id == square_id)
            return (int_to_vector(sq_ptr->color));
        sq_ptr = sq_ptr->next;
    }
    return (init_vector(0.0, 0.0, 0.0));
}

t_vector	obj_albedo(t_obj s, int obj_id[2])
{
	if (obj_id[0] == 1)
		return (sphere_albedo(s, obj_id[1]));
	else if (obj_id[0] == 2)
		return (plane_albedo(s, obj_id[1]));
	else if (obj_id[0] == 3)
        return (square_albedo(s, obj_id[1]));
	else if (obj_id[0] == 4)
		return (cylinder_albedo(s, obj_id[1]));
	else if (obj_id[0] == 5)
		return (triangle_albedo(s, obj_id[1]));
	return (init_vector(0, 0, 0));
}
