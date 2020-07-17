/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:49:20 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/17 16:00:18 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

int		rt_inter_triangle(const t_ray ray, const t_triangle tr, t_vector *P,
		t_vector *N, double *t)
{
	const double    epsilon = 0.0000001;

	t_vector	vertex0 = tr.p1;
	t_vector	vertex1 = tr.p2;
	t_vector	vertex2 = tr.p3;
	t_vector	edge1, edge2, h, s, q;
	double		a, f, u, v;
	edge1 = sub_vector(vertex1, vertex0);
	edge2 = sub_vector(vertex2, vertex0);
	h = prod_vector(ray.d, edge2);
	a = dot(edge1, h);
	if (a > -epsilon && a < epsilon)
		return (0);
	f = 1.0 / a;
	s = sub_vector(ray.o, vertex0);
	u = f * dot(s, h);
	if (u < 0.0 || u > 1.0)
		return (0);
	q = prod_vector(s, edge1);
	v = f * dot(ray.d, q);
	if (v < 0.0 || u + v > 1.0)
		return (0);
	*t = f * dot(edge2, q);
	if (*t > epsilon)
	{
		*P = add_vector(ray.o, mult_vector(*t, ray.d));
		*N = normalize(prod_vector(edge1, edge2));
		return (1);
	}
	return (0);
}

int		check_inter_triangle(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_triangle(check->ray, *(check->scene.lst_triangle),
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
			(check->obj_id)[0] = 5;
			(check->obj_id)[1] = check->scene.lst_triangle->id;
		}
		has_inter = 1;
	}
	return (has_inter);
}
