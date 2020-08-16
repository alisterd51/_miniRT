/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:24:50 by anclarma          #+#    #+#             */
/*   Updated: 2020/08/15 21:40:36 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "definex.h"
#include "libft.h"
#include "struct.h"
#include "parser.h"
#include "initpixel.h"
#include "input.h"
#include "screenshot.h"
#define WINDOW_TITLE "Test"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.screenshot = 0;
	if (ac == 2)
		parser(av[1], &(mlx.obj));
	else if (ac == 3 && !ft_strcmp(av[2], "--save"))
	{
		parser(av[1], &(mlx.obj));
		mlx.screenshot = 1;
	}
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
	//endroit ou mettre le screenshot!!
	if (mlx.screenshot)
	{
		ft_screenshot(&mlx);
		exit(0);
	}
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, ft_keypress, (void *)&mlx);
//	mlx_key_hook(mlx.win_ptr, deal_key, (void *)&mlx);
//	mlx_mouse_hook(mlx.win_ptr, deal_mouse, (void *)&mlx);
	mlx_hook(mlx.win_ptr, DestroyNotify, StructureNotifyMask, exit_hook, (void *)0);
	mlx_loop(mlx.mlx_ptr);
	exit(0);
}
