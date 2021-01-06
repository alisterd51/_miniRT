/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:50:28 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/06 17:21:13 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "vector.h"
#include "getcolor.h"

static t_vector	ft_mirror(t_test *test, t_ray *ray, t_obj *obj, int nbrebonds)
{
	t_ray	ray_mirror;

	ray_mirror.coord = sub_vector(ray->normal,
		mult_vector(2.0 * dot(test->n, ray->normal), test->n));
	ray_mirror.normal = add_vector(test->p, mult_vector(0.001, test->n));
	return (getcolor(&ray_mirror, obj, nbrebonds));
}

static t_vector	ft_transp(t_test *test, t_ray *ray, t_obj *obj, int nbrebonds)
{
	t_ray		ray_refract;
	t_vector	n_transp;
	double		n1;
	double		n2;
	double		radical;

	n1 = 1.0;
	n2 = 1.3;
	n_transp = test->n;
	if (dot(ray->normal, test->n) > 0.0)
	{
		n1 = 1.3;
		n2 = 1.0;
		n_transp = mult_vector(-1.0, test->n);
	}
	radical = 1.0 - sqrt(n1 / n2) * (1.0 - sqrt(dot(n_transp, ray->normal)));
	if (radical <= 0.0)
		return (init_vector(0.0, 0.0, 0.0));
	ray_refract.coord = sub_vector(mult_vector((n1 / n2),
		sub_vector(ray->normal, mult_vector(dot(ray->normal, n_transp),
		n_transp))), mult_vector(sqrt(radical), n_transp));
	ray_refract.normal = sub_vector(test->p, mult_vector(0.001, n_transp));
	return (getcolor(&ray_refract, obj, nbrebonds));
}

static t_vector	ft_direct(t_test *test, t_ray *ray, t_obj *obj, int nbrebonds)
{
	(void)test;
	(void)ray;
	(void)obj;
	(void)nbrebonds;
}

t_vector		getcolor(t_ray *ray, t_obj *obj, int nbrebonds)
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
			color = ft_direct(test, ray, obj, nbrebonds - 1);
	}
	return (color);
}
