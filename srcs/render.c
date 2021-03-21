/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:02:21 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/21 11:27:17 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "struct.h"
#include "vector.h"
#include "scenescan.h"
#include "exit_err.h"

static int	moyenne(t_mlx *mlx, int x, int y)
{
	t_vector	somme;
	int			i;
	int			j;

	somme = (t_vector){0, 0, 0};
	x *= mlx->aa;
	y *= mlx->aa;
	j = -1;
	while (++j < mlx->aa)
	{
		i = -1;
		while (++i < mlx->aa)
			somme = add_vector(somme, int_to_vector(mlx->image[(mlx->y_size
							- y - j - 1) * mlx->x_size + x + i]));
	}
	return (vector_to_ints(div_vector(somme, (mlx->aa * mlx->aa))));
}

void		oversampling(t_mlx *mlx)
{
	int			*image_final;
	int			x;
	int			y;

	image_final = mlx->image;
	mlx->y_size = mlx->y_size_aa;
	mlx->x_size = mlx->x_size_aa;
	mlx->image = mlx->aa_image;
	scenescan(mlx);
	y = -1;
	while (++y < mlx->y_save)
	{
		x = -1;
		while (++x < mlx->x_save)
			image_final[(mlx->y_save - y - 1) * mlx->x_save + x] =
				moyenne(mlx, x, y);
	}
	mlx->image = image_final;
	mlx->y_size = mlx->y_save;
	mlx->x_size = mlx->x_save;
}

void		prerendered(t_mlx *mlx)
{
	int			*image_final;
	int			x;
	int			y;

	image_final = mlx->image;
	mlx->y_size = mlx->y_size_iaa;
	mlx->x_size = mlx->x_size_iaa;
	mlx->image = mlx->iaa_image;
	scenescan(mlx);
	y = -1;
	while (++y < mlx->y_save)
	{
		x = -1;
		while (++x < mlx->x_save)
		{
			if (x / mlx->iaa >= mlx->x_size)
				image_final[y * mlx->x_save + x] = 0;
			else
				image_final[y * mlx->x_save + x] =
					mlx->image[(y / mlx->iaa) * mlx->x_size + (x / mlx->iaa)];
		}
	}
	mlx->image = image_final;
	mlx->y_size = mlx->y_save;
	mlx->x_size = mlx->x_save;
}

void		render(t_mlx *mlx)
{
	oversampling(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void		prerender(t_mlx *mlx)
{
	prerendered(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0X00FFFFFF,
			"pre-render");
}
