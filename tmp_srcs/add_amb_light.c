/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_amb_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:19:38 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/12 17:43:59 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>
#include "vector.h"
#include "albedo.h"

t_vector	add_amb_light(t_check *check, t_obj *obj)
{
	return (mult_vector(obj->amb_light->ratio * 40.0, obj_albedo(check)));
}
