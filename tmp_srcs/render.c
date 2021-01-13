/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:02:21 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/13 09:38:48 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "struct.h"
#include "vector.h"
#include "scenescan.h"

static int	moyenne(t_mlx *mlx, int x, int y)
{
	t_vector	somme;
	int			i;
	int			j;

	somme = init_vector(0.0, 0.0, 0.0);
	x *= mlx->aa;
	y *= mlx->aa;
	i = 0;
	while (i < mlx->aa)
	{
		j = 0;
		while (j < mlx->aa)
		{
			somme = add_vector(somme, int_to_vector(mlx->image[(mlx->y_size
							- x - i - 1) * mlx->x_size + y + j]));
			j++;
		}
		i++;
	}
	return (vector_to_ints(div_vector(somme, (mlx->aa * mlx->aa))));
}

void		oversampling(t_mlx *mlx)
{
	const int	y_native = mlx->y_size;
	const int	x_native = mlx->x_size;
	int			*image_final;
	int			x;
	int			y;

	image_final = mlx->image;
	mlx->y_size *= mlx->aa;
	mlx->x_size *= mlx->aa;
	mlx->image = malloc(mlx->y_size * mlx->x_size * sizeof(int));
	scenescan(mlx);
	x = -1;
	while (++x < y_native)
	{
		y = -1;
		while (++y < x_native)
			image_final[(y_native - x - 1) * x_native + y] = moyenne(mlx, x, y);
	}
	free(mlx->image);
	mlx->image = image_final;
	mlx->y_size = y_native;
	mlx->x_size = x_native;
}

void		prerendered(t_mlx *mlx)
{
	const int	y_native = mlx->y_size;
	const int	x_native = mlx->x_size;
	int			*image_final;
	int			x;
	int			y;

	image_final = mlx->image;
	mlx->y_size /= mlx->iaa;
	mlx->x_size /= mlx->iaa;
	mlx->image = malloc(mlx->y_size * mlx->x_size * sizeof(int));
	scenescan(mlx);
	x = -1;
	while (++x < y_native)
	{
		y = -1;
		while (++y < x_native)
			image_final[(y_native - x - 1) * x_native + y] =
				mlx->image[(mlx->y_size - x / mlx->iaa - 1) *
				mlx->x_size + y / mlx->iaa];
	}
	free(mlx->image);
	mlx->image = image_final;
	mlx->y_size = y_native;
	mlx->x_size = x_native;
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
