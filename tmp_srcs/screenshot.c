/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:07:16 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/11 10:09:53 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "struct.h"
#include "to_bmp.h"
#include "render.h"

void	ft_screenshot(t_mlx *mlx)
{
	oversampling(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	ft_tobmp(mlx, "test.bmp");
}
