/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:18:13 by anclarma          #+#    #+#             */
/*   Updated: 2021/02/01 10:47:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "struct.h"

/*
** check.c
*/
t_check	init_check(t_ray *ray, t_obj *obj, t_light *light);
void	res_check(t_check *dest, t_check *src);

#endif
