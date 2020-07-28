/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:43:02 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/28 11:30:51 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include <math.h>

int rt_inter_square(const t_ray ray, const t_square sq, t_vector *p,
        t_vector *n, double *t)
{
	double		a;
	double		b;
	double		t1;
	double		t2;
	t_vector	d;

	(void)p;
	(void)n;
	a = dot(sub_vector(ray.o, sq.c), sq.o);
	b = dot(ray.d, sq.o);
	if (b == 0.0 || (a < 0.0 && b < 0.0) || (a > 0.0 && b > 0.0))
		return (0);
	t1 = -a / b;
	d = sub_vector(add_vector(mult_vector(t1, ray.d), ray.o), sq.c);
	t2 = sq.height / 2;
	if (fabs(d.x) > t2 || fabs(d.y) > t2 || fabs(d.z) > t2)
		return (0);
	if (t1 <= 0.0)
		return (0);
	*t = t1;
	*p = add_vector(ray.o, mult_vector(*t, ray.d));
	*n = sq.o;
	return (1);
}

int	check_inter_square(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_square(check->ray, *(check->scene.lst_square),
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
			(check->obj_id)[0] = 3;
			(check->obj_id)[1] = check->scene.lst_square->id;
		}
		has_inter = 1;
	}
	return (has_inter);
}
