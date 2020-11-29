/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:32:22 by antoine           #+#    #+#             */
/*   Updated: 2020/11/29 16:08:12 by antoine          ###   ########.fr       */
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

#endif
