/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:50:28 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/06 15:20:41 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

t_vector	getcolor(const t_ray *ray, const t_obj *obj, int nbrebonds)
{
	t_vector	color;
	t_test		*test;
	int			has_inter;

	color = init_vector(0.0, 0.0, 0.0);
	if (nbrebonds == 0)
		return (color);
	test = init_test();
	has_inter = rt_inter_scene(test);
	if (has_inter)
	{
		if (this_obj_is_mirror(obj, test))
			color = ft_mirror(test, ray, obj, nbrebonds - 1);
		else if (this_obj_is_transp(obj, test))
			color = ft_transp(test, ray, obj, nbrebonds - 1);
		else
			color = ft_normal(test, ray, obj, nbrebonds - 1);
	}
	return (color);
}
