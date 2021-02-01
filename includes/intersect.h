/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:07:58 by anclarma          #+#    #+#             */
/*   Updated: 2021/02/01 15:53:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "struct.h"

int		rt_inter_scene(t_check *check);
int		check_inter_sphere(t_check *check);
int  inter_plane(t_check *local, t_plane *plane);
int		check_inter_plane(t_check *check);
int		check_inter_triangle(t_check *check);
int		check_inter_square(t_check *check);
int		check_inter_cylinder(t_check *check);
int		check_inter_cone(t_check *check);
int		rt_inter_sphere(const t_ray ray, const t_sphere sp, t_vector *p,
			t_vector *n, double *t);
int		rt_inter_plane(const t_ray ray, const t_plane pl, t_vector *p,
			t_vector *n, double *t);
int		rt_inter_plane_s(const t_ray ray, const t_plane pl, double *t);
int		rt_inter_triangle(const t_ray ray, const t_triangle tr, t_vector *p,
			t_vector *n, double *t);
int		rt_inter_square(const t_ray ray, const t_square sq, t_vector *p,
			t_vector *n, double *t);
int		rt_inter_cylinder(const t_ray ray, const t_cylinder cy, t_vector *p,
			t_vector *n, double *t);
#endif
