/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:43:02 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/21 13:32:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int rt_inter_square(const t_ray ray, const t_square sq, t_vector *p,
        t_vector *n, double *t)
{
	
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
