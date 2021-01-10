/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:36:50 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 09:56:14 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "intersect.h"
#include "vector.h"
#include <math.h>

#include <stdio.h>

int	rt_inter_sphere(const t_ray ray, const t_sphere s, t_vector *p,
		t_vector *n, double *t)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	a = 1;
	b = 2 * dot(ray.d, sub_vector(ray.o, s.c));
	c = norm2(sub_vector(ray.o, s.c)) - s.radius * s.radius;
	delta = b * b - 4.0 * a * c;
//	printf("a = %f, b = %f, c = %f, delta = %f\nray.o = %f, %f, %f\n", a, b, c, delta, ray.o.x, ray.o.y, ray.o.z);
	if (delta < 0)
		return (0);
	t1 = ((-b - sqrt(delta)) / (2 * a));
	t2 = ((-b + sqrt(delta)) / (2 * a));
	if (t2 < 0.0)
		return (0);
	if (t1 > 0.0)
		*t = t1;
	else
		*t = t2;
	*p = add_vector(ray.o, mult_vector(*t, ray.d));
	*n = normalize(sub_vector(*p, s.c));
	return (1);
}

int	check_inter_sphere(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_sphere(check->ray, *(check->scene.lst_sphere),
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
			(check->obj_id)[0] = 1;
			(check->obj_id)[1] = check->scene.lst_sphere->id;
		}
		has_inter = 1;
	}
	return (has_inter);
}
