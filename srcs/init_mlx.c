/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:16 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/14 10:28:05 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "struct.h"
#include "exit_err.h"

static void	set_mlx(t_mlx *mlx, t_obj *obj)
{
	int		x;
	int		y;

	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (exit_errcode(MLX_ERROR));
	mlx->x_size = obj->res->x_size;
	mlx->y_size = obj->res->y_size;
	mlx_get_screen_size(mlx->mlx_ptr, &x, &y);
	if (x < mlx->x_size)
		mlx->x_size = x;
	if (y - 50 < mlx->y_size)
		mlx->y_size = y - 50;
	mlx->size_line = obj->res->x_size * 4;
	mlx->bpp = 32;
	mlx->endian = 1;
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->x_size, mlx->y_size);
	mlx->image = (int *)mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->x_size,
			mlx->y_size, "Test");
	mlx->aa = 8;
	mlx->iaa = 16;
	obj->intensite_lumiere = 200000000.0;
	obj->current_cam = obj->lst_cam;
	mlx->obj = obj;
}

t_mlx		*init_mlx(t_obj *obj)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit_errcode(MALLOC_ERROR);
	set_mlx(mlx, obj);
	mlx->aa_image = (int *)malloc(mlx->y_size * mlx->x_size * mlx->aa
			* mlx->aa * sizeof(int));
	if (!mlx->aa_image)
		exit_errcode(MALLOC_ERROR);
	mlx->iaa_image = (int *)malloc((mlx->y_size / mlx->iaa + 1)
			* (mlx->x_size / mlx->iaa + 1) * sizeof(int));
	if (!mlx->iaa_image)
		exit_errcode(MALLOC_ERROR);
	return (mlx);
}
