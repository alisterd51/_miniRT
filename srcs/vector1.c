/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:09:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/10 11:47:31 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <math.h>

t_vector	add_vector(const t_vector a, const t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	sub_vector(const t_vector a, const t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	mult_vector(double a, const t_vector b)
{
	return ((t_vector){a * b.x, a * b.y, a * b.z});
}

t_vector	prod_vector(const t_vector a, const t_vector b)
{
	return ((t_vector){a.y * b.z - a.z * b.y,
						b.x * a.z - b.z * a.x,
						a.x * b.y - a.y * b.x});
}
