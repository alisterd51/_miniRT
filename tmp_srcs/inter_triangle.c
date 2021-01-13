/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:40:32 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/13 14:26:13 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "check.h"

static int	inter_triangle(t_check *local, t_triangle *triangle)
{
	t_calc_t	calc;

	calc.vertex0 = triangle->coord1;
	calc.vertex1 = triangle->coord2;
	calc.vertex2 = triangle->coord3;
	calc.edge1 = sub_vector(calc.vertex1, calc.vertex0);
	calc.edge2 = sub_vector(calc.vertex2, calc.vertex0);
	calc.h = prod_vector(local->ray.normal, calc.edge2);
	calc.a = dot(calc.edge1, calc.h);
	if (calc.a > -0.0000001 && calc.a < 0.0000001)
		return (0);
	calc.f = 1.0 / calc.a;
	calc.s = sub_vector(local->ray.coord, calc.vertex0);
	calc.u = calc.f * dot(calc.s, calc.h);
	if (calc.u < 0.0 || calc.u > 1.0)
		return (0);
	calc.q = prod_vector(calc.s, calc.edge1);
	calc.v = calc.f * dot(local->ray.normal, calc.q);
	if (calc.v < 0.0 || calc.u + calc.v > 1.0)
		return (0);
	local->t = calc.f * dot(calc.edge2, calc.q);
	if (local->t > 0.000001)
	{
		local->p = add_vector(local->ray.coord,
			mult_vector(local->t, local->ray.normal));
		local->n = normalize(prod_vector(calc.edge1, calc.edge2));
		return (1);
	}
	return (0);
}

int			check_inter_triangle(t_check *check)
{
	int			has_inter;
	int			id_triangle;
	t_check		local;
	t_triangle	*lst_triangle;

	lst_triangle = check->obj->lst_triangle;
	id_triangle = 0;
	has_inter = 0;
	local = init_check(&check->ray, check->obj, check->light);
	while (lst_triangle)
	{
		if (inter_triangle(&local, lst_triangle) && local.t < check->min_t)
		{
			has_inter = 1;
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			check->id_cat = 5;
			check->id_obj = id_triangle;
		}
		id_triangle++;
		lst_triangle = lst_triangle->next;
	}
	return (has_inter);
}
