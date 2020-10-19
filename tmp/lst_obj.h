/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:21:46 by anclarma          #+#    #+#             */
/*   Updated: 2020/10/19 14:28:59 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_OBJ_H
# define LST_OBJ_H

# include "struct.h"

t_obj	*init_obj(void);
void	print_obj(t_obj *obj);
void	free_obj(t_obj *obj);

#endif
