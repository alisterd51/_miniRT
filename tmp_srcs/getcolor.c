/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:50:28 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 07:52:52 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "vector.h"
#include "getcolor.h"
#include "this_obj_is.h"
#include "check.h"
#include "extremum.h"
#include "intersect.h"
#include "albedo.h"

static t_vector	ft_mirror(t_check *check, t_ray *ray, t_obj *obj, int nbrebonds)
{
	t_ray	ray_mirror;

	ray_mirror.coord = sub_vector(ray->normal,
		mult_vector(2.0 * dot(check->n, ray->normal), check->n));
	ray_mirror.normal = add_vector(check->p, mult_vector(0.001, check->n));
	return (getcolor(&ray_mirror, obj, nbrebonds));
}

static t_vector	ft_transp(t_check *check, t_ray *ray, t_obj *obj, int nbrebonds)
{
	t_ray		ray_refract;
	t_vector	n_transp;
	double		n1;
	double		n2;
	double		radical;

	n1 = 1.0;
	n2 = 1.3;
	n_transp = check->n;
	if (dot(ray->normal, check->n) > 0.0)
	{
		n1 = 1.3;
		n2 = 1.0;
		n_transp = mult_vector(-1.0, check->n);
	}
	radical = 1.0 - sqrt(n1 / n2) * (1.0 - sqrt(dot(n_transp, ray->normal)));
	if (radical <= 0.0)
		return (init_vector(0.0, 0.0, 0.0));
	ray_refract.coord = sub_vector(mult_vector((n1 / n2),
		sub_vector(ray->normal, mult_vector(dot(ray->normal, n_transp),
		n_transp))), mult_vector(sqrt(radical), n_transp));
	ray_refract.normal = sub_vector(check->p, mult_vector(0.001, n_transp));
	return (getcolor(&ray_refract, obj, nbrebonds));
}

static t_vector	ft_direct(t_check *check, t_obj *obj)
{
	t_check		check_light;
	t_ray		ray_light;
	int			has_inter_light;
	double		d_light2;

	ray_light.coord = add_vector(check->p, mult_vector(0.001, check->n));
	ray_light.normal = normalize(sub_vector(obj->lst_light->coord, check->p));
	check_light = init_check(&ray_light, obj);
	has_inter_light = rt_inter_scene(&check_light);
	d_light2 = norm2(sub_vector(obj->lst_light->coord, check->p));
	if (has_inter_light && check_light.t * check_light.t < d_light2)
		return (init_vector(0.0, 0.0, 0.0));
	else
		return (div_vector(mult_vector(obj->intensite_lumiere
			* max(0.0, dot(normalize(sub_vector(obj->lst_light->coord, check->p)),
			check->n)), div_vector(obj_albedo(check), M_PI)) , d_light2));
}

t_vector		getcolor(t_ray *ray, t_obj *obj, int nbrebonds)
{
	t_vector	color;
	t_check		check;
	int			has_inter;

	color = init_vector(0.0, 0.0, 0.0);
	if (nbrebonds == 0)
		return (color);
	check = init_check(ray, obj);
	has_inter = rt_inter_scene(&check);
	if (has_inter)
	{
		if (this_obj_is_mirror(&check))
			color = ft_mirror(&check, ray, obj, nbrebonds - 1);
		else if (this_obj_is_transp(&check))
			color = ft_transp(&check, ray, obj, nbrebonds - 1);
		else
			color = ft_direct(&check, obj);
	}
	return (color);
}
