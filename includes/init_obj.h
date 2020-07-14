/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:15:02 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/13 10:51:45 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_OBJ_H
# define INIT_OBJ_H

# include "struct.h"

void		init_obj(t_obj *obj);
int			init_res(char *line, t_obj *obj);
int			init_amblight(char *line, t_obj *obj);
int			init_cam(char *line, t_obj *obj);
int			init_light(char *line, t_obj *obj);
int			init_sphere(char *line, t_obj *obj);
int			init_plane(char *line, t_obj *obj);
int			init_square(char *line, t_obj *obj);
int			init_cylinder(char *line, t_obj *obj);
int			init_triangle(char *line, t_obj *obj);
int			read_int(char **line);
double		read_float(char **line);
t_vector	read_vec(char **line);
int			read_color(char **line);
int			read_option(char **line);
int			read_option2(char **line);

#endif
