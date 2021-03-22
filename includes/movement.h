/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:34:03 by pompier           #+#    #+#             */
/*   Updated: 2021/03/21 13:36:12 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

/*
** movement.c
*/
int	num_key(int key, t_mlx *mlx);
int	translation_key(int key, t_mlx *mlx);
int	rotation_key(int key, t_mlx *mlx);
int	next_cam(t_mlx *mlx);
int	prev_cam(t_mlx *mlx);

#endif
