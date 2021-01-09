/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:57:53 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 10:08:16 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_check	init_check(t_ray *ray, t_obj *obj)
{
	t_check	ret;

	ret.id_cat = 0;
	ret.id_obj = 0;
	ret.min_t = 1e99;
	ret.t = 1e99;
	ret.ray = *ray;
	ret.obj = obj;
	return (ret);
}
