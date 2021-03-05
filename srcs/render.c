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

	somme = init_vector(0.0, 0.0, 0.0);
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
	const int	y_native = mlx->y_size;
	const int	x_native = mlx->x_size;
	int			*image_final;
	int			x;
	int			y;

	image_final = mlx->image;
	mlx->y_size *= mlx->aa;
	mlx->x_size *= mlx->aa;
	mlx->image = (int *)ft_calloc(mlx->y_size * mlx->x_size, sizeof(int));
	if (mlx->image == NULL)
		return (exit_errcode(MALLOC_ERROR));
	scenescan(mlx);
	y = -1;
	while (++y < y_native)
	{
		x = -1;
		while (++x < x_native)
			image_final[(y_native - y - 1) * x_native + x] = moyenne(mlx, x, y);
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
	mlx->image = (int *)ft_calloc((mlx->y_size + 1) * (mlx->x_size + 1), sizeof(int));
	if (mlx->image == NULL)
		return (exit_errcode(MALLOC_ERROR));
	scenescan(mlx);
	y = -1;
	while (++y < y_native)
	{
		x = -1;
		while (++x < x_native)
		{
			if (x / mlx->iaa >= mlx->x_size)
				image_final[y * x_native + x] = 0;
			else
				image_final[y * x_native + x] =
					mlx->image[(y / mlx->iaa) * mlx->x_size + (x / mlx->iaa)];
		}
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
