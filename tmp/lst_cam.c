/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:41:39 by antoine           #+#    #+#             */
/*   Updated: 2020/11/22 17:58:32 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "exit_err.h"
#include "read_line.h"
#include "libft.h"

void	init_lst_cam(char *line, t_obj *obj)
{
	t_cam	*cam;
	t_cam	*tmp_cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (exit_errcode(MALLOC_ERROR));
	cam->coord = read_line_to_vector(&line);
	cam->normal = read_line_to_vector(&line);
	cam->fov = read_line_to_int(&line);
	if (*line && !ft_isspace(*line))
		return (exit_errcode(CAM_ERROR_LINE));
	cam->parameter = read_line_to_string(&line);
	if (!cam->parameter)
		return (exit_errcode(MALLOC_ERROR));
	cam->next = NULL;
	if (!obj->lst_cam)
		obj->lst_cam = cam;
	else
	{
		tmp_cam = obj->lst_cam;
		while (tmp_cam->next)
			tmp_cam = tmp_cam->next;
		tmp_cam->next = cam;
	}
}

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
