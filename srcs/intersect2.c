/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:36:50 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/14 16:36:52 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "intersect.h"
#include "vector.h"
#include <math.h>

int	rt_inter_sphere(const t_ray ray, const t_sphere s, t_vector *P,
		t_vector *N, double *t)
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
	*P = add_vector(ray.o, mult_vector(*t, ray.d));
	*N = normalize(sub_vector(*P, s.c));
	return (1);
}

int	check_inter_sphere(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_sphere(check->ray, *(check->scene.lst_sphere),
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
			(check->obj_id)[0] = 1;
			(check->obj_id)[1] = check->scene.lst_sphere->id;
		}
		has_inter = 1;
	}
	return (has_inter);
}
