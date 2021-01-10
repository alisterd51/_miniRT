/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:57:05 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 11:37:39 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "extremum.h"
#include "this_obj_is.h"
#include "albedo.h"
#include "intersect.h"
#include <math.h>
#include <stdio.h>
t_vector	getcolor(const t_ray *r, const t_obj *s, int nbrebonds)
{
	if (nbrebonds == 0)
		return (init_vector(0.0, 0.0, 0.0));

	t_vector	p, n;
	//	int			sphere_id = 0;
	int			obj_id[2] = {0, 0};
	//	int			type_obj = 0;
	//	int			obj_id = 0;
	double		t;

	//
	t_check_scene	check;

	check.scene = *s;
	check.ray = *r;
	(check.obj_id)[0] = 0;
	(check.obj_id)[1] = 0;
	//
	(void)t;
	//
	int			has_inter = rt_inter_scene(&check);
	//
	p = check.p;
	n = check.n;
	obj_id[0] = (check.obj_id)[0];
	obj_id[1] = (check.obj_id)[1];
	t = check.t;
	//
	t_vector	intensite_pixel = init_vector(0.0, 0.0, 0.0);

	if (has_inter)
	{
		if (this_obj_is_mirror(*s, obj_id))
		{
			t_ray	ray_mirror;

			ray_mirror.d = sub_vector(r->d, mult_vector(2.0 * dot(n, r->d), n));
			ray_mirror.o = add_vector(p, mult_vector(0.001, n));
			intensite_pixel = getcolor(&ray_mirror, s, nbrebonds - 1);
		}
		else if (this_obj_is_transp(*s, obj_id))
		{
			t_ray   ray_refract;
			t_vector	N_transp = n;
			double	n1 = 1.0;
			double	n2 = 1.3;

			if (dot(r->d, n) > 0.0)
			{
				n1 = 1.3;
				n2 = 1.0;
				N_transp = mult_vector(-1.0, n);
			}

			double	radical = 1.0 - sqrt(n1/n2) * (1 - sqrt(dot(N_transp, r->d)));
			if (radical > 0.0)
			{
				ray_refract.d = sub_vector(mult_vector((n1 / n2), sub_vector(r->d, mult_vector(dot(r->d, N_transp), N_transp))), mult_vector(sqrt(radical), N_transp));
				ray_refract.o = sub_vector(p, mult_vector(0.001, N_transp));
				intensite_pixel = getcolor(&ray_refract, s, nbrebonds - 1);
			}
		}
		else
		{
			t_ray		ray_light;
			ray_light.d = normalize(sub_vector(s->lst_light->c, p));
			ray_light.o = add_vector(p, mult_vector(0.001, n));
			t_vector	P_light, N_light;
			int			obj_id_light[2] = {0, 0};
			double		t_light;
			//
			t_check_scene   check_light;

			check_light.scene = *s;
			check_light.ray = ray_light;
			(check_light.obj_id)[0] = 0;
			(check_light.obj_id)[1] = 0;
			//
			int			has_inter_light = rt_inter_scene(&check_light);
			//
			P_light = check.p;
			N_light = check.n;
			obj_id_light[0] = (check_light.obj_id)[0];
			obj_id_light[1] = (check_light.obj_id)[1];
			t_light = check_light.t;
			//
			(void)obj_id_light;
			(void)P_light;
			(void)N_light;
			//
			double		d_light2 = norm2(sub_vector(s->lst_light->c, p));

			if (has_inter_light && t_light * t_light < d_light2)
			{
				intensite_pixel = init_vector(0.0, 0.0, 0.0);
				//a placer dans une fonction d'éclairage ambiant
				//intensite_pixel = mult_vector(s->amblight->ratio * 20, div_vector(obj_albedo(*s, obj_id), M_PI));
			}
			else
			{
				intensite_pixel = div_vector(mult_vector(s->intensite_lumiere * max(0.0, dot(normalize(sub_vector(s->lst_light->c, p)) , n)), div_vector(obj_albedo(*s, obj_id), M_PI)) , d_light2);
			}
			/*en attente générateur nb aléatoire.
			  t_ray   ray_alea;
			  double		r1 = ;//nb entre 0 et 1, distribution normal aléatoire.
			  t_vector	dir_alea_repere_local = ;

			  ray_alea.d = ;
			  ray_alea.o = add_vector(P, mult_vector(0.001, N));
			  intensite_pixel = add_vector(intensite_pixel, getcolor(&ray_alea, s, nbrebonds - 1));*/
		}
	}
	return (intensite_pixel);
}
