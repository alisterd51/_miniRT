/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:34:14 by anclarma          #+#    #+#             */
/*   Updated: 2021/02/02 09:17:13 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "check.h"
#include "vector.h"
#include "intersect.h"

static int	inter_cylinder(t_check *local, t_cylinder *cylinder)
{
	t_calc	calc;
	double	dist;
	double	dist1;
	double	dist2;

	calc.v = sub_vector(local->ray.normal, mult_vector(dot(local->ray.normal,
		cylinder->normal), cylinder->normal));
	calc.u = sub_vector(sub_vector(local->ray.coord, cylinder->coord),
		mult_vector(dot(sub_vector(local->ray.coord, cylinder->coord),
		cylinder->normal), cylinder->normal));
	calc.a = dot(calc.v, calc.v);
	calc.b = 2 * dot(calc.v, calc.u);
	calc.c = dot(calc.u, calc.u) - cylinder->radius2;
	calc.delta = calc.b * calc.b - 4.0 * calc.a * calc.c;
	if (calc.delta < 0)
		return (0);
	calc.t1 = ((-(calc.b) - sqrt(calc.delta)) / (2 * calc.a));
	calc.t2 = ((-(calc.b) + sqrt(calc.delta)) / (2 * calc.a));
	if (calc.t1 < 0.001 && calc.t2 < 0.001)
		return (0);
	dist1 = dot(cylinder->normal, sub_vector(mult_vector(calc.t1,
		local->ray.normal), sub_vector(cylinder->coord, local->ray.coord)));
	dist2 = dot(cylinder->normal, sub_vector(mult_vector(calc.t2,
		local->ray.normal), sub_vector(cylinder->coord, local->ray.coord)));
	if ((dist1 >= 0 && dist1 <= cylinder->height && calc.t1 > 0.001)
			&& (dist2 >= 0 && dist2 <= cylinder->height && calc.t2 > 0.001))
	{
		local->t = calc.t1 < calc.t2 ? calc.t1 : calc.t2;
		dist = calc.t1 < calc.t2 ? dist1 : dist2;
	}
	else if (dist1 >= 0 && dist1 <= cylinder->height && calc.t1 > 0.001)
	{
		local->t = calc.t1;
		dist = dist1;
	}
	else
	{
		local->t = calc.t2;
		dist = dist2;
	}
	if (dist < 0 || dist > cylinder->height)
		return (0);
	local->n = normalize(sub_vector(sub_vector(mult_vector(local->t,
		local->ray.normal), mult_vector(dist, cylinder->normal)),
		sub_vector(cylinder->coord, local->ray.coord)));
	local->p = add_vector(local->ray.coord, 
		mult_vector(local->t, local->ray.normal));
	return (1);
}

double      distance(t_vector p1, t_vector p2)
{
    double d;

    d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
    return (d);
}
#include <unistd.h>
static int	inter_cap(t_check *local_caps, t_cylinder *cylinder)
{
	t_plane		plane1;
	t_plane		plane2;
	t_check		local1;
	t_check		local2;
	t_check     *local_min;

	plane1.normal = cylinder->normal;
	plane1.coord = cylinder->coord;
	plane2.normal = cylinder->normal;
	plane2.coord = add_vector(cylinder->coord,
		mult_vector(cylinder->height, cylinder->normal));
	local1 = init_check(&local_caps->ray, local_caps->obj, local_caps->light);
	local2 = init_check(&local_caps->ray, local_caps->obj, local_caps->light);
	if (inter_plane(&local1, &plane1) || inter_plane(&local2, &plane2))
	{
		if (local1.t > 0 && (local1.t < local2.t || local2.t < 0)
				&& distance(local1.p, plane1.coord) <= cylinder->diameter / 2)
		{		
			local_min = &local1;
		}
		else if (local2.t > 0 && (local2.t < local1.t || local1.t < 0)
				&& distance(local2.p, plane2.coord) <= cylinder->diameter / 2)
		{		
			return (0);
			local_min = &local2;
		}
		else
			return (0);
		res_check(local_caps, local_min);
		return (1);
	}
	return (0);
}

static int	inter_cy_and_caps(t_check *local, t_cylinder *cylinder)
{
	t_check		local_cy;
	t_check		local_caps;
	t_check		*local_min;

	local_cy = init_check(&local->ray, local->obj, local->light);
	local_caps = init_check(&local->ray, local->obj, local->light);
	if (inter_cylinder(&local_cy, cylinder)
		|| inter_cap(&local_caps, cylinder))
	{
		if (local_cy.t < local_caps.t)
			local_min = &local_cy;
		else
			local_min = &local_caps;
		res_check(local, local_min);
		return (1);
	}
	return (0);
}

int			check_inter_cylinder(t_check *check)
{
	int			has_inter;
	int			id_cylinder;
	t_check		local;
	t_cylinder	*lst_cylinder;

	lst_cylinder = check->obj->lst_cylinder;
	id_cylinder = 0;
	has_inter = 0;
	local = init_check(&check->ray, check->obj, check->light);
	while (lst_cylinder)
	{
		if (inter_cy_and_caps(&local, lst_cylinder) && local.t < check->min_t)
		{
			has_inter = 1;
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			check->id_cat = 4;
			check->id_obj = id_cylinder;
		}
		id_cylinder++;
		lst_cylinder = lst_cylinder->next;
	}
	return (has_inter);
}
