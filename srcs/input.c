/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:29:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/21 13:32:21 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "input.h"
#include "render.h"
#include "screenshot.h"
#include "movement.h"

/*
** DESCRIPTION
*/

int			ft_keypress(int key, t_mlx *mlx)
{
	if (key == R_KEY)
		render(mlx);
	else if (key == P_KEY)
		ft_screenshot(mlx);
	else if (key == ESC_KEY)
		exit_hook(mlx);
	else if (key == PAGE_UP)
		next_cam(mlx);
	else if (key == PAGE_DOWN)
		prev_cam(mlx);
	else if (translation_key(key, mlx) || rotation_key(key, mlx)
			|| num_key(key, mlx))
		prerender(mlx);
	else
		return (0);
	return (1);
}
