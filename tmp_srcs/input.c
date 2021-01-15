/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:29:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/15 13:27:05 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "struct.h"
#include "lst_obj.h"
#include "input.h"
#include "rot_vector.h"
#include "render.h"

/*
** DESCRIPTION
*/

int			exit_hook(t_mlx *mlx)
{
	int	i;

	(void)mlx;
	i = -1;
	while (++i < mlx->y_size)
		free(mlx->pixel[i]);
	free(mlx->pixel);
	free_obj(&(mlx->obj));
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	exit(0);
	return (0);
}

/*
** DESCRIPTION
*/

static int	prerender_key(int key, t_mlx *mlx)
{
	if (key == UP_KEY)
		mlx->obj->current_cam->coord.z -= 1;
	else if (key == DOWN_KEY)
		mlx->obj->current_cam->coord.z += 1;
	else if (key == S_KEY)
		mlx->obj->current_cam->coord.y -= 1;
	else if (key == Z_KEY)
		mlx->obj->current_cam->coord.y += 1;
	else if (key == LEFT_KEY)
		mlx->obj->current_cam->coord.x -= 1;
	else if (key == RIGHT_KEY)
		mlx->obj->current_cam->coord.x += 1;
	else if (key == Q_KEY)
		mlx->obj->current_cam->normal =
			rot_z_vector(M_PI / 9, mlx->obj->current_cam->normal);
	else if (key == D_KEY)
		mlx->obj->current_cam->normal =
			rot_z_vector(M_PI / -9, mlx->obj->current_cam->normal);
	else
		return (0);
	return (1);
}

/*
** DESCRIPTION
*/

static int	next_cam(t_mlx *mlx)
{
	t_cam	*ptr_cam;

	ptr_cam = mlx->obj->lst_cam;
	while (ptr_cam->id < mlx->obj->current_cam->id)
		ptr_cam = ptr_cam->next;
	if (!ptr_cam->next)
		mlx->obj->current_cam = mlx->obj->lst_cam;
	else
		mlx->obj->current_cam = ptr_cam->next;
	prerender(mlx);
	return (1);
}

/*
** DESCRIPTION
*/

static int	prev_cam(t_mlx *mlx)
{
	t_cam	*ptr_cam;

	ptr_cam = mlx->obj->lst_cam;
	if (!mlx->obj->current_cam->id)
		while (ptr_cam->next)
			ptr_cam = ptr_cam->next;
	else
		while (ptr_cam->id < mlx->obj->current_cam->id - 1)
			ptr_cam = ptr_cam->next;
	mlx->obj->current_cam = ptr_cam;
	prerender(mlx);
	return (1);
}

/*
** DESCRIPTION
*/

int			ft_keypress(int key, t_mlx *mlx)
{
	if (key == R_KEY)
		render(mlx);
	else if (key == ESC_KEY)
		exit_hook(mlx);
	else if (key == PAGE_UP)
		next_cam(mlx);
	else if (key == PAGE_DOWN)
		prev_cam(mlx);	
	else if (prerender_key(key, mlx))
		prerender(mlx);
	else
		return (0);
	return (1);
}
