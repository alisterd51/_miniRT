/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_obj_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 10:32:07 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/10 10:51:42 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int			this_sp_is_mirror(t_obj s, int sphere_id)
{
	t_sphere	*s_ptr;

	s_ptr = s.lst_sphere;
	while (s_ptr)
	{
		if (s_ptr->id == sphere_id)
			return (s_ptr->mirror);
		s_ptr = s_ptr->next;
	}
	return (0);
}


int			this_obj_is_mirror(t_obj s, int obj_id[2])
{
	if (obj_id[0] == 1)
		return (this_sp_is_mirror(s, obj_id[1]));
	return (0);
}

int         this_sp_is_transp(t_obj s, int sphere_id)
{
	t_sphere    *s_ptr;

	s_ptr = s.lst_sphere;
	while (s_ptr)
	{
		if (s_ptr->id == sphere_id)
			return (s_ptr->transp);
		s_ptr = s_ptr->next;
	}
	return (0);
}

int			this_obj_is_transp(t_obj s, int obj_id[2])
{
	if (obj_id[0] == 1)
		return (this_sp_is_transp(s, obj_id[1]));
	return (0);
}
