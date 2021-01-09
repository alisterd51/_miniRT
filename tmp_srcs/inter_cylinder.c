/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:34:14 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 16:40:07 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static int	inter_cylinder(t_check *local, t_cylinder *cylinder)
{
	//a faire
	(void)local;
	(void)cylinder;
	return (0);
}

int			check_inter_cylinder(t_check *check)
{
	int			has_inter;
	int			id_cylinder;
	t_check		local;
	t_cylinder	*lst_cylinder;

	lst_cylinder = check->obj->lst_cylinder;
	id_cylinder = 0;
	has_inter = 0;
	while (lst_cylinder)
	{
		if (inter_cylinder(&local, lst_cylinder) && local.t < check->min_t)
		{
			has_inter = 1;
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			check->id_cat = 4;
			check->id_obj = id_cylinder;
		}
		id_cylinder++;
		lst_cylinder = lst_cylinder->next;
	}
	return (has_inter);
}
