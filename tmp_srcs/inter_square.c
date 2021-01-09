/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:18:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 15:44:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "vector.h"

static int	inter_square(t_check *local, t_square *square)
{
	t_calc		calc;
	t_vector	d;

	calc.a = dot(sub_vector(local->ray.coord, square->coord), square->normal);
	calc.b = dot(local->ray.normal, square->normal);
	if (calc.b == 0.0 || (calc.a < 0.0 && calc.b < 0.0)
		|| (calc.a > 0.0 && calc.b > 0.0))
		return (0);
	calc.t1 = -(calc.a) / calc.b;
	d = sub_vector(add_vector(mult_vector(calc.t1, local->ray.coord),
		local->ray.normal), square->coord);
	calc.t2 = square->side / 2.0;
	if (fabs(d.x) > calc.t2 || fabs(d.y) > calc.t2 || fabs(d.z) > calc.t2)
		return (0);
	if (calc.t1 <= 0.0)
		return (0);
	local->t = calc.t1;
	local->p = add_vector(local->ray.coord,
		mult_vector(local->t, local->ray.normal));
	local->n = square->normal;
	return (1);
}

int			check_inter_square(t_check *check)
{
	int			has_inter;
	int			id_square;
	t_check		local;
	t_square	*lst_square;

	lst_square = check->obj->lst_square;
	id_square = 0;
	has_inter = 0;
	while (lst_square)
	{
		if (inter_square(&local, lst_square) && local.t < check->min_t)
		{
			has_inter = 1;
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			check->id_cat = 3;
			check->id_obj = id_square;
		}
		id_square++;
		lst_square = lst_square->next;
	}
	return (has_inter);
}
