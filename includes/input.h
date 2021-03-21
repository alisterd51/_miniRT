/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:46:00 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/21 13:24:19 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "struct.h"

/*
** MACINTOSH_INPUT
*/
# ifdef MACOS
#  define UP_KEY	126
#  define DOWN_KEY	125
#  define LEFT_KEY	123
#  define RIGHT_KEY	124
#  define Z_KEY		6
#  define S_KEY		1
#  define R_KEY		15
#  define Q_KEY		12
#  define D_KEY		2
#  define H_KEY		4
#  define J_KEY		38
#  define K_KEY		40
#  define L_KEY		37
#  define P_KEY		35
#  define ZERO_KEY	82
#  define ONE_KEY	83
#  define TWO_KEY	84
#  define THREE_KEY	85
#  define FOUR_KEY	86
#  define FIVE_KEY	87
#  define SIX_KEY	88
#  define SEVEN_KEY	89
#  define EIGHT_KEY	91
#  define NINE_KEY	92
#  define ESC_KEY	53
#  define PAGE_UP	116
#  define PAGE_DOWN	121
# endif

/*
** LINUX_WSL_INPUT
*/
# ifdef LINUX
#  define UP_KEY	65362
#  define DOWN_KEY	65364
#  define LEFT_KEY	65361
#  define RIGHT_KEY	65363
#  define Z_KEY		122
#  define S_KEY		115
#  define R_KEY		114
#  define Q_KEY		113
#  define D_KEY		100
#  define H_KEY		104
#  define J_KEY		106
#  define K_KEY		107
#  define L_KEY		108
#  define P_KEY		112
#  define ZERO_KEY	65438
#  define ONE_KEY	65436
#  define TWO_KEY	65433
#  define THREE_KEY	65435
#  define FOUR_KEY	65430
#  define FIVE_KEY	65437
#  define SIX_KEY	65432
#  define SEVEN_KEY	65429
#  define EIGHT_KEY	65431
#  define NINE_KEY	65434
#  define ESC_KEY	65307
#  define PAGE_UP	65365
#  define PAGE_DOWN	65366
# endif

/*
** input.c
*/
int	deal_mouse(int button, int x, int y, t_mlx *mlx);
int	deal_key(int key, t_mlx *mlx);
int	ft_keypress(int key, t_mlx *mlx);
int	ft_keyrelease(int key, t_mlx *mlx);

/*
** exit_hook.c
*/
int	exit_hook(t_mlx *mlx);

#endif
