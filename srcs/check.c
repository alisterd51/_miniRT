/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:57:53 by anclarma          #+#    #+#             */
/*   Updated: 2021/02/01 10:46:50 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

t_check	init_check(t_ray *ray, t_obj *obj, t_light *light)
{
	t_check	ret;

	ret.id_cat = 0;
	ret.id_obj = 0;
	ret.min_t = 1e99;
	ret.t = 1e99;
	ret.ray = *ray;
	ret.p = init_vector(0.0, 0.0, 0.0);
	ret.n = init_vector(0.0, 0.0, 0.0);
	ret.obj = obj;
	ret.light = light;
	return (ret);
}

void	res_check(t_check *dest, t_check *src)
{
	dest->id_cat = src->id_cat;
	dest->id_obj = src->id_obj;
	dest->min_t = src->min_t;
	dest->t = src->t;
	dest->ray = src->ray;
	dest->p = src->p;
	dest->n = src->n;
	dest->obj = src->obj;
	dest->light = src->light;
}
