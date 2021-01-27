/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:55:07 by anclarma          #+#    #+#             */
/*   Updated: 2020/12/08 16:54:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "lst_obj.h"

t_obj	*init_obj(void)
{
	t_obj	*obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->res = NULL;
	obj->amb_light = NULL;
	obj->lst_cam = NULL;
	obj->lst_light = NULL;
	obj->lst_sphere = NULL;
	obj->lst_plane = NULL;
	obj->lst_square = NULL;
	obj->lst_cylinder = NULL;
	obj->lst_triangle = NULL;
	obj->lst_cone = NULL;
	return (obj);
}

void	free_obj(t_obj **obj)
{
	if (!*obj)
		return ;
	free_res(*obj);
	free_amb_light(*obj);
	free_lst_cam(*obj);
	free_lst_light(*obj);
	free_lst_sphere(*obj);
	free_lst_plane(*obj);
	free_lst_square(*obj);
	free_lst_cylinder(*obj);
	free_lst_triangle(*obj);
	free_lst_cone(*obj);
	free(*obj);
	*obj = NULL;
}
