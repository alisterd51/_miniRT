/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:05:27 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 11:32:32 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "struct.h"

/*
** vector1.c
*/
t_vector	init_vector(double x, double y, double z);
t_vector	add_vector(const t_vector a, const t_vector b);
t_vector	sub_vector(const t_vector a, const t_vector b);
t_vector	mult_vector(double a, const t_vector b);
t_vector	prod_vector(const t_vector a, const t_vector b);

/*
** vector2.c
*/
t_vector	div_vector(const t_vector a, double b);
double		dot(const t_vector a, const t_vector b);
double		norm2(const t_vector vector);
t_vector	normalize(t_vector vector);

/*
** vector3.c
*/
t_vector	int_to_vector(int color);
int			vector_to_int(t_vector vec);
int			vector_to_ints(t_vector vec);
t_vector	color_to_vector(t_color color);

#endif
