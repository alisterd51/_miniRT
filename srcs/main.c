/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:43:51 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/31 14:04:58 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "lst_obj.h"
#include "parsing.h"
#include "exit_err.h"
#include "input.h"
#include "libft.h"
#include "screenshot.h"

static int		ft_save(char *param)
{
	if (!ft_strcmp(param, "--save"))
		return (1);
	return (0);
}

static t_mlx	*init_mlx(t_obj *obj)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit_errcode(MALLOC_ERROR);
	mlx->x_size = obj->res->x_size;
	mlx->y_size = obj->res->y_size;
	mlx->mlx_ptr = mlx_init();
	mlx->size_line = obj->res->x_size * 4;
	mlx->bpp = 32;
	mlx->endian = 1;
	mlx_get_screen_size(mlx->mlx_ptr, &x, &y);
	if (x < mlx->x_size)
		mlx->x_size = x;
	if (y - 50 < mlx->y_size)
		mlx->y_size = y - 50;
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->x_size, mlx->y_size);
	mlx->image = (int *)mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->x_size,
			mlx->y_size, "Test");
	mlx->aa = 10;
	mlx->iaa = 11;
	mlx->nb_thread = 8;
	obj->intensite_lumiere = 200000000.0;
	obj->current_cam = obj->lst_cam;
	mlx->aa_image = (int *)calloc(mlx->y_size * mlx->x_size * mlx->aa * mlx->aa, sizeof(int));
	mlx->iaa_image = (int *)calloc((mlx->y_size / mlx->iaa + 1) * (mlx->x_size / mlx->iaa + 1), sizeof(int));
	mlx->obj = obj;
	return (mlx);
}

int				main(int ac, char **av)
{
	t_obj	*obj;
	t_mlx	*mlx;
	int		save;

	obj = init_obj();
	if (!obj)
		exit_errcode(MALLOC_ERROR);
	save = 0;
	if (ac == 3 && ft_save(av[2]))
		save = 1;
	if (ac != 2 && !save)
	{
		exit_errcode(ARGC_ERROR);
		return (1);
	}
	parsing(av[1], obj);
	mlx = init_mlx(obj);
	if (save)
		ft_screenshot(mlx);
	mlx_hook(mlx->win_ptr, 2, (1L << 0), ft_keypress, (void *)mlx);
	mlx_hook(mlx->win_ptr, 17, (1L << 17), exit_hook, (void *)0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
