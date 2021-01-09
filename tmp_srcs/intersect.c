/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:18:49 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 13:25:51 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "intersect.h"

int	rt_inter_scene(t_check *check)
{
	int	has_inter;

	has_inter = 0;
	has_inter += check_inter_sphere(check);
	has_inter += check_inter_plane(check);
	has_inter += check_inter_square(check);
	has_inter += check_inter_cylinder(check);
	has_inter += check_inter_triangle(check);
	has_inter += check_inter_cone(check);
	return (has_inter);
}
