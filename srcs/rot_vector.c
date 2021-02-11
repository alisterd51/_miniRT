/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:53:21 by antoine           #+#    #+#             */
/*   Updated: 2021/02/11 14:49:47 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"

t_vector	rot_x_vector(double rot, t_vector vector)
{
	t_vector	ret;

	ret.x = vector.x * cos(rot) - vector.y * sin(rot);
	ret.y = vector.x * sin(rot) + vector.y * cos(rot);
	ret.z = vector.z;
	return (ret);
}

t_vector	rot_y_vector(double rot, t_vector vector)
{
	t_vector	ret;

	ret.y = vector.y * cos(rot) - vector.z * sin(rot);
	ret.z = vector.y * sin(rot) + vector.z * cos(rot);
	ret.x = vector.x;
	return (ret);
}

t_vector	rot_z_vector(double rot, t_vector vector)
{
	t_vector	ret;

	ret.z = vector.z * cos(rot) - vector.x * sin(rot);
	ret.x = vector.z * sin(rot) + vector.x * cos(rot);
	ret.y = vector.y;
	return (ret);
}

t_vector	rot_vector(t_vector rot, t_vector vector)
{
	t_vector	ret;

	ret = rot_x_vector(rot.x, vector);
	ret = rot_y_vector(rot.y, ret);
	ret = rot_z_vector(rot.z, ret);
	return (ret);
}

t_vector	init_rot(t_vector rot)
{
	t_vector	ret;

	ret.x = rot.x * M_PI / 2.0;
	ret.y = rot.y * M_PI / 2.0;
	ret.z = rot.z * M_PI - M_PI;
	return (ret);
}
