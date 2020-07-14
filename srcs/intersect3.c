/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:16:21 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/14 17:32:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

int		rt_inter_plane(const t_ray ray, const t_plane p, t_vector *P, t_vector *N, double *t)
{
	*N = p.o;
	if (dot(ray.d, *N) == 0.0)
		return (0);
	*t = dot(sub_vector(p.c, ray.o), p.o) / dot(ray.d, *N);
	if (*t < 0.0)
		return (0);
	*P = add_vector(ray.o, mult_vector(*t, ray.d));
	return (1);
}

int		check_inter_plane(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_plane(check->ray, *(check->scene.lst_plane),
			&(local.P), &(local.N), &(local.t));
	has_inter = 0;
	if (local.has_inter)
	{
		if (local.t < check->min_t)
		{
			check->min_t = local.t;
			check->t = local.t;
			check->P = local.P;
			check->N = local.N;
			(check->obj_id)[0] = 2;
			(check->obj_id)[1] = check->scene.lst_plane->id;
		}
		has_inter = 1;
	}
	return (has_inter);
}
