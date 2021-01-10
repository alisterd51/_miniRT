/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenescan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:58:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/10 10:19:23 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <math.h>
#include "struct.h"
#include "vector.h"
#include "getcolor.h"

static void	*fonction(void *arg)
{
	t_arg	*a;
	t_mlx	*mlx;
	t_ray	ray;
	int		x;
	int		y;

	a = (t_arg*)arg;
	mlx = a->mlx;
	x = -1;
	while (++x < mlx->y_size)
	{
		y = a->y_min - 1;
		while (++y < a->y_max)
		{
			ray.coord = mlx->obj->lst_cam->coord;
			ray.normal = add_vector(init_vector(y - mlx->x_size / 2, x -
				mlx->y_size / 2, -(mlx->x_size) / (2 *
				tanf(mlx->obj->lst_cam->fov_rad / 2))),
				mlx->obj->lst_cam->normal);
			ray.normal = normalize(ray.normal);
			mlx->image[(mlx->y_size - x - 1) * mlx->x_size + y] =
				vector_to_int(getcolor(&ray, mlx->obj, 20));
		}
	}
	return (NULL);
}

int			scenescan(t_mlx *mlx)
{
	pthread_t	thread[mlx->nb_thread];
	t_arg		arg[mlx->nb_thread];
	int			num_thread;

	num_thread = -1;
	while (++num_thread < mlx->nb_thread)
	{
		arg[num_thread].mlx = mlx;
		if (num_thread == 0)
			arg[num_thread].y_min = 0;
		else
			arg[num_thread].y_min = arg[num_thread - 1].y_max;
		arg[num_thread].y_max = mlx->x_size * (num_thread + 1) / mlx->nb_thread;
		if (pthread_create(&(thread[num_thread]), NULL, fonction,
				&(arg[num_thread])))
			return (1);
	}
	num_thread = -1;
	while (++num_thread < mlx->nb_thread)
		if (pthread_join(thread[num_thread], NULL))
			return (1);
	return (0);
}
