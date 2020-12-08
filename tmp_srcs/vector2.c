/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:13:46 by anclarma          #+#    #+#             */
/*   Updated: 2020/12/08 16:34:04 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include <math.h>

t_vector	div_vector(const t_vector a, double b)
{
	return (init_vector(a.x / b, a.y / b, a.z / b));
}

double		dot(const t_vector a, const t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		norm2(const t_vector vector)
{
	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

t_vector	normalize(t_vector vector)
{
	double		norm;
	t_vector	vec;

	norm = sqrt(norm2(vector));
	vec.x = vector.x / norm;
	vec.y = vector.y / norm;
	vec.z = vector.z / norm;
	return (vec);
}
