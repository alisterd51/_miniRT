/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:35:10 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 15:02:31 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "check.h"

static int	inter_cone(t_check *local, t_cone *cone)
{
	//a faire
	(void)local;
	(void)cone;
	return (0);
}

int			check_inter_cone(t_check *check)
{
	int			has_inter;
	int			id_cone;
	t_check		local;
	t_cone	*lst_cone;

	lst_cone = check->obj->lst_cone;
	id_cone = 0;
	has_inter = 0;
	local = init_check(&check->ray, check->obj);
	while (lst_cone)
	{
		if (inter_cone(&local, lst_cone) && local.t < check->min_t)
		{
			has_inter = 1;
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			check->id_cat = 6;
			check->id_obj = id_cone;
		}
		id_cone++;
		lst_cone = lst_cone->next;
	}
	return (has_inter);
}
