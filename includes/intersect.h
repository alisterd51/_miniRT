/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:07:58 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/13 19:26:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "struct.h"

int		rt_inter_scene(t_check_scene *check);
int		check_inter_sphere(t_check_scene *check);
int		check_inter_plane(t_check_scene *check);
int		rt_inter_sphere(const t_ray ray, const t_sphere s, t_vector *P,
			t_vector *N, double *t);
int		rt_inter_plane(const t_ray ray, const t_sphere s, t_vector *P,
			t_vector *N, double *t);

#endif
