/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:29:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/05 17:43:12 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "struct.h"
#include "lst_obj.h"
#include "input.h"
#include "rot_vector.h"

/*
**
*/
int	exit_hook(t_mlx *mlx)
{
	int	i;

	(void)mlx;
	i = -1;
	while (++i < mlx->y_size)
		free(mlx->pixel[i]);
	free(mlx->pixel);
	free_obj(&(mlx->obj));
	mlx_destroy_image (mlx->mlx_ptr, mlx->img_ptr);
	exit(0);
	return (0);
}

/*
**
*/
int     ft_keypress(int key, t_mlx *mlx)
{
    if (key == R_KEY)
		render(mlx);
	else if (key == UP_KEY)
		mlx->obj->lst_cam->coord.z -= 1;
	else if (key == DOWN_KEY)
        mlx->obj->lst_cam->coord.z += 1;
	else if (key == S_KEY)
        mlx->obj->lst_cam->coord.y -= 1;
	else if (key == Z_KEY)
        mlx->obj->lst_cam->coord.y += 1;
	else if (key == LEFT_KEY)
        mlx->obj->lst_cam->coord.x -= 1;
    else if (key == RIGHT_KEY)
        mlx->obj->lst_cam->coord.x += 1;
    else if (key == Q_KEY)
        mlx->obj->lst_cam->normal = rot_z_vector(M_PI / 9, mlx->obj->lst_cam->normal);
    else if (key == D_KEY)
        mlx->obj->lst_cam->normal = rot_z_vector(M_PI / -9, mlx->obj->lst_cam->normal);
    else if (key == ESC_KEY)
		exit_hook(mlx);
	else
		return (0);
	prerender(mlx);
	return (0);
}
