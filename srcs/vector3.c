/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:15:58 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/21 16:47:46 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "extremum.h"
#include <math.h>

t_vector	int_to_vector(int color)
{
	t_vector	new_vec;

	new_vec.x = color % 256;
	color /= 256;
	new_vec.y = color % 256;
	color /= 256;
	new_vec.z = color % 256;
	return (new_vec);
}

int			vector_to_int(t_vector vec)
{
	int			ret;

	ret = (int)max(0.0, min(255.0, pow(vec.x, 1 / 2.2))) +
		(int)max(0.0, min(255.0, pow(vec.y, 1 / 2.2))) * 256 +
		(int)max(0.0, min(255.0, pow(vec.z, 1 / 2.2))) * 256 * 256;
	return (ret);
}

int			vector_to_ints(t_vector vec)
{
	int			ret;

	ret = (int)max(0.0, min(255.0, vec.x)) +
		(int)max(0.0, min(255.0, vec.y)) * 256 +
		(int)max(0.0, min(255.0, vec.z)) * 256 * 256;
	return (ret);
}

//modifie un veteur d'oriantation
// 1	0	0	devant 
// 0	x	x	droite ou gauche (ou haut ou bas)
// -1	0	0	derriere
// 0	x	x	droite ou gauche (ou haut ou bas)
// angle en rad: 0ª = 0, 90ª = ¶/2
// x * cos(-angle) - y * sin(-angle)
// x * sin(-angle) + y * cos(-angle)

t_vector	rot_right(t_vector o, double angle)
{
	t_vector	new_o;

	new_o.x = o.z * cos(-angle) + o.x * sin(-angle);
	new_o.y = o.y;
	new_o.z = o.z * sin(-angle) - o.x * cos(-angle);
	return (new_o);
}

t_vector	rot_left(t_vector o, double angle)
{
	t_vector    new_o;

    new_o.x = o.z * cos(angle) + o.x * sin(angle);
    new_o.y = o.y;
    new_o.z = o.z * sin(angle) - o.x * cos(angle);
    return (new_o);
}
