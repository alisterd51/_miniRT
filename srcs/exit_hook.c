/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:40:32 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/08 13:49:48 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "struct.h"
#include "lst_obj.h"

int	exit_hook(t_mlx *mlx)
{
	free(mlx->aa_image);
	free(mlx->iaa_image);
	free_obj(&(mlx->obj));
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	exit(0);
	return (0);
}
