/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:29:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/21 13:36:42 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "render.h"
#include "input.h"

/*
** DESCRIPTION
*/

int	num_key(int key, t_mlx *mlx)
{
	if (key == ZERO_KEY)
		mlx->obj->lst_light->coord.x -= 1;
	else if (key == ONE_KEY)
		mlx->obj->lst_light->coord.x += 1;
	else if (key == TWO_KEY)
		mlx->obj->lst_light->coord.y -= 1;
	else if (key == THREE_KEY)
		mlx->obj->lst_light->coord.y += 1;
	else if (key == FOUR_KEY)
		mlx->obj->lst_light->coord.z -= 1;
	else if (key == FIVE_KEY)
		mlx->obj->lst_light->coord.z += 1;
	else if (key == SIX_KEY)
		(void)mlx;
	else if (key == SEVEN_KEY)
		(void)mlx;
	else if (key == EIGHT_KEY)
		(void)mlx;
	else if (key == NINE_KEY)
		(void)mlx;
	else
		return (0);
	return (1);
}

int	translation_key(int key, t_mlx *mlx)
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
	else
		return (0);
	return (1);
}

int	rotation_key(int key, t_mlx *mlx)
{
	if (key == K_KEY)
		mlx->obj->current_cam->rot.x -= M_PI / 100.0;
	else if (key == L_KEY)
		mlx->obj->current_cam->rot.x += M_PI / 100.0;
	else if (key == H_KEY)
		mlx->obj->current_cam->rot.y -= M_PI / 100.0;
	else if (key == J_KEY)
		mlx->obj->current_cam->rot.y += M_PI / 100.0;
	else if (key == D_KEY)
		mlx->obj->current_cam->rot.z -= M_PI / 100.0;
	else if (key == Q_KEY)
		mlx->obj->current_cam->rot.z += M_PI / 100.0;
	else
		return (0);
	return (1);
}

/*
** DESCRIPTION
*/

int	next_cam(t_mlx *mlx)
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

int	prev_cam(t_mlx *mlx)
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
