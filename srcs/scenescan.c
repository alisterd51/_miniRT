/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenescan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:58:35 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/14 16:25:00 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "getcolor.h"
#include <pthread.h>
#include <math.h>

void	*fonction(void *arg)
{
	t_arg			*a;
	t_mlx			*mlx;
	t_ray			ray;
	int				x;
	int				y;
	const double	fov = 70 * M_PI / 180;

	a = (t_arg*)arg;
	mlx = a->mlx;
	mlx->obj.intensite_lumiere = 1000000;
	x = 0;
	while (x < mlx->height)
	{
		y = a->y_min;
		while (y < a->y_max)
		{
			ray.o = mlx->obj.lst_cam->c;
			ray.d = add_vector(init_vector(y - mlx->width / 2, x -
					mlx->height / 2, -(mlx->width) / (2 * tanf(fov / 2))),
					mlx->obj.lst_cam->vec);
			ray.d = normalize(ray.d);
			mlx->image[(mlx->height - x - 1) * mlx->width + y] =
				vector_to_int(getcolor(&ray, &(mlx->obj), 20));
			y++;
		}
		x++;
	}
	return (NULL);
}

int		scenescan(t_mlx *mlx)
{
	pthread_t	thread1, thread2, thread3, thread4;
	t_arg		arg1, arg2, arg3, arg4;

	arg1.mlx = mlx;
	arg2.mlx = mlx;
	arg3.mlx = mlx;
	arg4.mlx = mlx;
	arg1.y_min = 0;
	arg1.y_max = mlx->width / 4;
	arg2.y_min = arg1.y_max;
	arg2.y_max = mlx->width / 2;
	arg3.y_min = arg2.y_max;
	arg3.y_max = (mlx->width / 4) * 3;
	arg4.y_min = arg3.y_max;
	arg4.y_max = mlx->width;
	if (pthread_create(&thread1, NULL, fonction, &arg1))
		return (1);
	if (pthread_create(&thread2, NULL, fonction, &arg2))
		return (1);
	if (pthread_create(&thread3, NULL, fonction, &arg3))
		return (1);
	if (pthread_create(&thread4, NULL, fonction, &arg4))
		return (1);
	if (pthread_join(thread1, NULL))
		return (1);
	if (pthread_join(thread2, NULL))
		return (1);
	if (pthread_join(thread3, NULL))
		return (1);
	if (pthread_join(thread4, NULL))
		return (1);
	return (0);
}
