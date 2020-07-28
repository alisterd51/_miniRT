/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:48:24 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/28 12:53:13 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int rt_inter_cylinder(const t_ray ray, const t_cylinder cy, t_vector *p,
        t_vector *n, double *t)
{
}

int	check_inter_cylinder(t_check_scene *check)
{
	int			has_inter;
	t_local		local;

	local.has_inter = rt_inter_cylinder(check->ray, *(check->scene.lst_cylinder),
			&(local.p), &(local.n), &(local.t));
	has_inter = 0;
	if (local.has_inter)
	{
		if (local.t < check->min_t)
		{
			check->min_t = local.t;
			check->t = local.t;
			check->p = local.p;
			check->n = local.n;
			(check->obj_id)[0] = 6;
			(check->obj_id)[1] = check->scene.lst_cylinder->id;
		}
		has_inter = 1;
	}
	return (has_inter);
}
