/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:48:24 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/28 16:55:07 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	plane(t_mini_rt *rt, t_element *plane, t_vec ori, t_vec dir)
{
	a = vec_dot(vec_sub(ori, plane->point), plane->orient);
	b = vec_dot(dir, plane->orient);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return ;
	t = -a / b;
	if (t < 0 || rt->t < t)
		return ;
	rt->t = t;
}

int rt_inter_cylinder(const t_ray ray, const t_cylinder cy, t_vector *p,
        t_vector *n, double *t)
{
	cross = prod_vector(ray.d, cy.o);
	sub = sub_vector(ray.o, cy.c);
	cross2 = prod_vector(sub, cy.o);
	a = norm2(cross);
	b = 2.0 * dot(cross, cross2);
	c = norm2(cross2) - pow(cy.radius, 2) * norm2(cy.o);
	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0.0)
		return (0);
	a *= 2;
	delta = sqrt(delta);
	t1 = ((-b - sqrt(delta)) / (2 * a));
	t2 = ((-b + sqrt(delta)) / (2 * a));
	if (t1 >= 0)
		t = t1;
	else if (t2 >= 0)
		t = t2;
	else
		return (0);
	inter = add_vector(ray.o, mult_vector(t, cy.o));

	double	sub_t;
	t_plane	pl;
	t_ray	sub_ray;

	pl.c = cy.c;
	pl.o = cy.c;
	sub_ray.o = inter;
	sub_ray.d = cy.o;
	if (rt_inter_plane_s(sub_ray, pl, &sub_t) && sub_t <= cy.height / 2.0)
		return (1);
	sub_ray = mult_vector(-1.0, cy.o);
	if (rt_inter_plane_s(sub_ray, pl, &sub_t) && sub_t <= cy.height / 2.0)
		return (1);
	return (0);
}//a finir https://github.com/solaldunckel/miniRT/blob/master/srcs/cylinder.c

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
