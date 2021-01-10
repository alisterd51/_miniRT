/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:16:21 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 14:57:07 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

int     rt_inter_plane_s(const t_ray ray, const t_plane pl, double *t)
{
    if (dot(ray.d, pl.o) == 0.0)
        return (0);
    *t = dot(sub_vector(pl.c, ray.o), pl.o) / dot(ray.d, pl.o);
    if (*t < 0.0)
        return (0);
    return (1);
}

int		rt_inter_plane(const t_ray ray, const t_plane pl, t_vector *p,
		t_vector *n, double *t)
{
	*n = pl.o;
	if (dot(ray.d, *n) == 0.0)
		return (0);
	*t = dot(sub_vector(pl.c, ray.o), pl.o) / dot(ray.d, *n);
	if (*t < 0.0)
		return (0);
	*p = add_vector(ray.o, mult_vector(*t, ray.d));
	return (1);
}

int		check_inter_plane(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_plane(check->ray, *(check->scene.lst_plane),
			&(local.p), &(local.n), &(local.t));
	has_inter = 0;
	if (local.has_inter)
	{
		if (local.t < check->min_t)
		{
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			(check->obj_id)[0] = 2;
			(check->obj_id)[1] = check->scene.lst_plane->id;
		}
		has_inter = 1;
	}
	return (has_inter);
}
