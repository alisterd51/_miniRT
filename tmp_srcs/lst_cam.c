/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:41:39 by antoine           #+#    #+#             */
/*   Updated: 2021/01/06 14:29:43 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

/*
** DESCRIPTION
**	ajoute la camera en parametre a la liste des cameras de la scene.
*/

void	add_end_lst_cam(t_cam *new_cam, t_obj *obj)
{
	t_cam	*tmp_cam;

	if (!obj->lst_cam)
		obj->lst_cam = new_cam;
	else
	{
		tmp_cam = obj->lst_cam;
		while (tmp_cam->next)
			tmp_cam = tmp_cam->next;
		tmp_cam->next = new_cam;
	}
}

/*
** DESCRIPTION
**	Cette fonction lit une ligne normalise et parametre une camera
**	de la scene.
** ERRORS
**	En cas de parametre incorecte, la fonction exit_errcode est appelle avec
**	un code approprie.
*/

void	init_lst_cam(char *line, t_obj *obj)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		return (exit_errcode(MALLOC_ERROR));
	cam->coord = read_line_to_vector(&line);
	cam->normal = read_line_to_vector(&line);
	cam->fov = read_line_to_int(&line);
	cam->fov_rad = cam->fov * M_PI / 180.0;
	if (*line && !ft_isspace(*line))
		return (exit_errcode(CAM_ERROR_LINE));
	cam->parameter = read_line_to_string(&line);
	if (!cam->parameter)
		return (exit_errcode(MALLOC_ERROR));
	cam->next = NULL;
	add_end_lst_cam(cam, obj);
}

/*
** DESCRIPTION
**	La fonction libere toute la liste de camera de la scene.
*/

void	free_lst_cam(t_obj *obj)
{
	t_cam	*cam;
	t_cam	*next_cam;

	cam = obj->lst_cam;
	while (cam)
	{
		next_cam = cam->next;
		if (cam->parameter)
			free(cam->parameter);
		free(cam);
		cam = next_cam;
	}
	obj->lst_cam = NULL;
}
