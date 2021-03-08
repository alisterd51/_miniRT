/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:43:51 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/08 12:13:32 by pompier          ###   ########.fr       */
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
#include "init_mlx.h"

static int	ft_save(char *param)
{
	if (!ft_strcmp(param, "--save"))
		return (1);
	return (0);
}

int			main(int ac, char **av)
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
