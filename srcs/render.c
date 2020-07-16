/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:02:21 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/16 15:26:53 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "scenescan.h"
#include "vector.h"
#include <stdlib.h>
#include <mlx.h>

static int	moyenne(int param_aa, t_mlx *mlx, int x, int y)
{
	t_vector	somme;
	int			i;
	int			j;

	somme = init_vector(0.0, 0.0, 0.0);
	x *= param_aa;
	y *= param_aa;
	i = 0;
	while (i < param_aa)
	{
		j = 0;
		while (j < param_aa)
		{
			somme = add_vector(somme, int_to_vector(mlx->image[(mlx->height
							- x - i - 1) * mlx->width + y + j]));
			j++;
		}
		i++;
	}
	return (vector_to_ints(div_vector(somme, (param_aa * param_aa))));
}

void		oversampling(t_mlx *mlx)
{
	const int	height_native = mlx->height;
	const int	width_native = mlx->width;
	int			*image_final = mlx->image;
	int			param_aa = 4;
	int			x;
	int			y;

	mlx->height *= param_aa;
	mlx->width *= param_aa;
	mlx->image = malloc(mlx->height * mlx->width * sizeof(int));
	scenescan(mlx);
	x = 0;
	while (x < height_native)
	{
		y = 0;
		while(y < width_native)
		{
			image_final[(height_native - x - 1) * width_native + y] =
				moyenne(param_aa, mlx, x, y);
			y++;
		}
		x++;
	}
	free(mlx->image);
	mlx->image = image_final;
	mlx->height = height_native;
	mlx->width = width_native;
}

void        prerendered(t_mlx *mlx)
{
	const int   height_native = mlx->height;
	const int   width_native = mlx->width;
	int         *image_final = mlx->image;
	int         param = 16;
	int         x;
	int         y;

	mlx->height /= param;
	mlx->width /= param;
	mlx->image = malloc(mlx->height * mlx->width * sizeof(int));
	scenescan(mlx);
	x = 0;
	while (x < height_native)
	{
		y = 0;
		while(y < width_native)
		{
			image_final[(height_native - x - 1) * width_native + y] =
				mlx->image[(mlx->height - x / param - 1) * mlx->width + y / param];
			y++;
		}
		x++;
	}
	free(mlx->image);
	mlx->image = image_final;
	mlx->height = height_native;
	mlx->width = width_native;
}

void	render(t_mlx *mlx)
{
	oversampling(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	prerender(t_mlx *mlx)
{
	prerendered(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0X00FFFFFF, "pre-render");
}
