/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:07:12 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/09 11:34:50 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>

void	initpixel(t_mlx *mlx)
{
	int	i;

	mlx->pixel = malloc(sizeof(int *) * mlx->obj.resolution->y_size);
	i = -1;
	while (++i < mlx->obj.resolution->y_size)
		mlx->pixel[i] = malloc(sizeof(int) * mlx->obj.resolution->x_size);
	mlx->size_line = mlx->obj.resolution->x_size * 4;
	mlx->bpp = 32;
	mlx->endian = 1;
}
