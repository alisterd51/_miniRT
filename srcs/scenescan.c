/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenescan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:58:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 10:49:49 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "getcolor.h"
#include <pthread.h>
#include <math.h>
#define NB_THREAD	1

void	*fonction(void *arg)
{
	t_arg			*a;
	t_mlx			*mlx;
	t_ray			ray;
	int				x;
	int				y;
	double			fov;

	a = (t_arg*)arg;
	mlx = a->mlx;
	fov = mlx->obj.lst_cam->fov * M_PI / 180;
	mlx->obj.intensite_lumiere = 2000000;
	x = -1;
	while (++x < mlx->height)
	{
		y = a->y_min - 1;
		while (++y < a->y_max)
		{
			ray.o = mlx->obj.lst_cam->c;
			ray.d = add_vector(init_vector(y - mlx->width / 2, x -
					mlx->height / 2, -(mlx->width) / (2 * tanf(fov / 2))),
					mlx->obj.lst_cam->vec);
			ray.d = normalize(ray.d);
			mlx->image[(mlx->height - x - 1) * mlx->width + y] =
				vector_to_int(getcolor(&ray, &(mlx->obj), 20));
		}
	}
	return (NULL);
}

int		scenescan(t_mlx *mlx)
{
	pthread_t	thread[NB_THREAD];
	t_arg		arg[NB_THREAD];
	int			num_thread;

	num_thread = -1;
	while (++num_thread < NB_THREAD)
	{
		arg[num_thread].mlx = mlx;
		if (num_thread == 0)
			arg[num_thread].y_min = 0;
		else
			arg[num_thread].y_min = arg[num_thread - 1].y_max;
		arg[num_thread].y_max = mlx->width * (num_thread + 1) / NB_THREAD;
		if (pthread_create(&(thread[num_thread]), NULL, fonction, &(arg[num_thread])))
			return (1);
	}
	num_thread = -1;
	while (++num_thread < NB_THREAD)
		if (pthread_join(thread[num_thread], NULL))
			return (1);
	return (0);
}
