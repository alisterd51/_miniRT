/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:46:00 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/27 11:36:40 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "struct.h"
# define UP_KEY		126
# define DOWN_KEY	125
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define Z_KEY		6
# define S_KEY		1
# define R_KEY		15
# define Q_KEY		12
# define D_KEY		2
# define ESC_KEY	53
/*
# define UP_KEY		65362
# define DOWN_KEY	65364
# define LEFT_KEY	65361
# define RIGHT_KEY	65363
# define Z_KEY		122
# define S_KEY		115
# define R_KEY		114
# define Q_KEY		113
# define D_KEY		100
# define ESC_KEY	65307
*/
int	deal_mouse(int button, int x, int y, t_mlx *mlx);
int	deal_key(int key, t_mlx *mlx);
int	ft_keypress(int key, t_mlx *mlx);
int	ft_keyrelease(int key, t_mlx *mlx);
int     exit_hook(t_mlx *mlx);

#endif
