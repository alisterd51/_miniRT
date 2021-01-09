/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_obj_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:25:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 10:50:35 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"

static int	this_sphere_is_mirror(t_sphere *lst_sphere, int id_sphere)
{
	while (id_sphere-- > 0)
		lst_sphere = lst_sphere->next;
	if (!ft_strcmp(lst_sphere->parameter, "m"))
		return (1);
	return (0);
}

int			this_obj_is_mirror(t_check *check)
{
	if (check->id_cat == 1)
		return (this_sphere_is_mirror(check->obj->lst_sphere, check->id_obj));
	return (0);
}

static int	this_sphere_is_transp(t_sphere *lst_sphere, int id_sphere)
{
	while (id_sphere-- > 0)
		lst_sphere = lst_sphere->next;
	if (!ft_strcmp(lst_sphere->parameter, "t"))
		return (1);
	return (0);
}

int			this_obj_is_transp(t_check *check)
{
	if (check->id_cat == 1)
		return (this_sphere_is_transp(check->obj->lst_sphere, check->id_obj));
	return (0);
}
