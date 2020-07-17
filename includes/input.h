/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:46:00 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/17 10:21:01 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define UP_KEY		126
# define DOWN_KEY	125
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define Z_KEY		6
# define S_KEY		1
# define R_KEY		15
# define ESC_KEY	53
/*
# define UP_KEY		65362
# define DOWN_KEY	65364
# define LEFT_KEY	65361
# define RIGHT_KEY	65363
# define Z_KEY		122
# define S_KEY		115
# define R_KEY		114
# define ESC_KEY	65307
*/
int	deal_mouse(int button, int x, int y, void *param);
int	deal_key(int key, void *param);

#endif
