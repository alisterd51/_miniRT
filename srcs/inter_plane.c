/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:46:28 by anclarma          #+#    #+#             */
/*   Updated: 2021/02/01 15:53:40 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "check.h"

int			inter_plane(t_check *local, t_plane *plane)
{
	local->n = plane->normal;
	if (dot(local->ray.normal, local->n) == 0.0)
		return (0);
	local->t = dot(sub_vector(plane->coord, local->ray.coord), plane->normal)
		/ dot(local->ray.normal, local->n);
	if (local->t < 0.0)
		return (0);
	local->p = add_vector(local->ray.coord,
		mult_vector(local->t, local->ray.normal));
	return (1);
}

int			check_inter_plane(t_check *check)
{
	int			has_inter;
	int			id_plane;
	t_check		local;
	t_plane		*lst_plane;

	lst_plane = check->obj->lst_plane;
	id_plane = 0;
	has_inter = 0;
	local = init_check(&check->ray, check->obj, check->light);
	while (lst_plane)
	{
		if (inter_plane(&local, lst_plane) && local.t < check->min_t)
		{
			has_inter = 1;
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			check->id_cat = 2;
			check->id_obj = id_plane;
		}
		id_plane++;
		lst_plane = lst_plane->next;
	}
	return (has_inter);
}
