/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:35:10 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 15:02:13 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "vector.h"
#include "check.h"

static int	inter_sphere(t_check *local, t_sphere *sphere)
{
	t_calc	calc;

	calc.a = 1;
	calc.b = 2 * dot(local->ray.normal,
		sub_vector(local->ray.coord, sphere->coord));
	calc.c = norm2(sub_vector(local->ray.coord, sphere->coord))
		- sphere->radius2;
	calc.delta = calc.b * calc.b - 4.0 * calc.a * calc.c;
	if (calc.delta < 0)
		return (0);
	calc.t1 = ((-(calc.b) - sqrt(calc.delta)) / (2 * calc.a));
	calc.t2 = ((-(calc.b) + sqrt(calc.delta)) / (2 * calc.a));
	if (calc.t2 < 0.0)
		return (0);
	if (calc.t1 > 0.0)
		local->t = calc.t1;
	else
		local->t = calc.t2;
	local->p = add_vector(local->ray.coord,
		mult_vector(local->t, local->ray.normal));
	local->n = normalize(sub_vector(local->p, sphere->coord));
	return (1);
}

int			check_inter_sphere(t_check *check)
{
	int			has_inter;
	int			id_sphere;
	t_check		local;
	t_sphere	*lst_sphere;

	lst_sphere = check->obj->lst_sphere;
	id_sphere = 0;
	has_inter = 0;
	local = init_check(&check->ray, check->obj);
	while (lst_sphere)
	{
		if (inter_sphere(&local, lst_sphere) && local.t < check->min_t)
		{
			has_inter = 1;
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			check->id_cat = 1;
			check->id_obj = id_sphere;
		}
		id_sphere++;
		lst_sphere = lst_sphere->next;
	}
	return (has_inter);
}
