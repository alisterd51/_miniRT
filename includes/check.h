/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:18:13 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/31 14:03:42 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "struct.h"

/*
** check.c
*/
t_check	init_check(t_ray *ray, t_obj *obj, t_light *light);

#endif
