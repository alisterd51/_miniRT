/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:24:50 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/21 16:47:40 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "struct.h"
#include "parser.h"
#include "initpixel.h"
#include "input.h"
#define WINDOW_TITLE "Test"

#include "render.h"

int	loop_hook(void *param)
{
	t_mlx   *mlx;

	mlx = (t_mlx *)param;
	prerender(mlx);
	return (0);
}//test

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
		parser(av[1], &(mlx.obj));
	else
	{
		ft_printf("veuillez indiquer un fichier .rt en argument\n");
		exit(0);
	}
	mlx.width = mlx.obj.resolution->x_size;
	mlx.height = mlx.obj.resolution->y_size;
	mlx.mlx_ptr = mlx_init();
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.width, mlx.height);
	mlx.image = (int *)mlx_get_data_addr(mlx.img_ptr, &(mlx.bpp),
			&(mlx.size_line), &(mlx.endian));
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width,
			mlx.height, WINDOW_TITLE);
	initpixel(&mlx);
	mlx_loop_hook (mlx.mlx_ptr, loop_hook, (void *)&mlx );
	mlx_key_hook(mlx.win_ptr, deal_key, (void *)&mlx);
	mlx_mouse_hook(mlx.win_ptr, deal_mouse, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
	exit(0);
}
