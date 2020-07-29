/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:48:24 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/29 14:51:16 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "intersect.h"
#include <math.h>

#include <stdio.h>

int rt_inter_cylinder(const t_ray ray, const t_cylinder cy, t_vector *p,
        t_vector *n, double *t)
{
	t_vector	cross;
	t_vector	cross2;
	t_vector	sub;
	t_vector	inter;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t1;
	double		t2;
	
	//erreur volontaire
	*p = add_vector(ray.o, mult_vector(*t, ray.d));
    *n = normalize(sub_vector(*p, cy.c));
	//
	cross = prod_vector(ray.d, cy.o);
	sub = sub_vector(ray.o, cy.c);
	cross2 = prod_vector(sub, cy.o);
	a = norm2(cross);
	b = 2.0 * dot(cross, cross2);
	c = norm2(cross2) - pow(cy.radius, 2) * norm2(cy.o);
	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0.0)
		return (0);
	a *= 2;
	delta = sqrt(delta);
	t1 = ((-b - delta) / a);
	t2 = ((-b + delta) / a);
	if (t1 >= 0)
		*t = t1;
	else if (t2 >= 0)
		*t = t2;
	else
		return (0);
	inter = add_vector(ray.o, mult_vector(*t, cy.o));

	double	sub_t;
	t_plane	pl;
	t_ray	sub_ray;
	int		ret;

	ret = 0;
	pl.c = cy.c;
	pl.o = cy.c;
	sub_ray.o = inter;
	sub_ray.d = cy.o;
	if (rt_inter_plane_s(sub_ray, pl, &sub_t) && sub_t <= cy.height / 2.0)//
	{
		//vue d'au dessus
	}
	sub_ray.d = mult_vector(-1.0, cy.o);
	if (rt_inter_plane_s(sub_ray, pl, &sub_t) && sub_t <= cy.height / 2.0)//
	{
		//vue dans dessous
	}
	return (1);
}//a finir https://github.com/solaldunckel/miniRT/blob/master/srcs/cylinder.c

int	check_inter_cylinder(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_cylinder(check->ray, *(check->scene.lst_cylinder),
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
			(check->obj_id)[0] = 4;
			(check->obj_id)[1] = check->scene.lst_cylinder->id;
		}
		has_inter = 1;
		printf("yep");
	}
	return (has_inter);
}
