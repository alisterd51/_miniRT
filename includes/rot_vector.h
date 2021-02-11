/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:32:22 by antoine           #+#    #+#             */
/*   Updated: 2021/02/11 14:50:25 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROT_VECTOR_H
# define ROT_VECTOR_H

# include "struct.h"

/*
** rot_vector.c
*/
t_vector	rot_x_vector(double rot, t_vector vector);
t_vector	rot_y_vector(double rot, t_vector vector);
t_vector	rot_z_vector(double rot, t_vector vector);
t_vector	rot_vector(t_vector rot, t_vector vector);
t_vector	init_rot(t_vector rot);

#endif
