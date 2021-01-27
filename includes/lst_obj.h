/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:21:46 by anclarma          #+#    #+#             */
/*   Updated: 2021/01/09 11:41:37 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_OBJ_H
# define LST_OBJ_H

# include "struct.h"

/*
** lst_obj.c
*/
t_obj	*init_obj(void);
void	print_obj(t_obj *obj);
void	free_obj(t_obj **obj);

/*
** res.c
*/
void	init_res(char *line, t_obj *obj);
void	free_res(t_obj *obj);

/*
** amb_light.c
*/
void	init_amb_light(char *line, t_obj *obj);
void	free_amb_light(t_obj *obj);

/*
** lst_cam.c
*/
void		add_end_lst_cam(t_cam *new_cam, t_obj *obj);
void		init_lst_cam(char *line, t_obj *obj);
void		free_lst_cam(t_obj *obj);

/*
** lst_light.c
*/
void		add_end_lst_light(t_light *new_light, t_obj *obj);
void		init_lst_light(char *line, t_obj *obj);
void		free_lst_light(t_obj *obj);

/*
** lst_sphere.c
*/
void		add_end_lst_sphere(t_sphere *new_sphere, t_obj *obj);
void		init_lst_sphere(char *line, t_obj *obj);
void		free_lst_sphere(t_obj *obj);
t_vector	sphere_albedo(t_sphere *lst_sphere, int id_sphere);

/*
** lst_plane.c
*/
void		add_end_lst_plane(t_plane *new_plane, t_obj *obj);
void		init_lst_plane(char *line, t_obj *obj);
void		free_lst_plane(t_obj *obj);
t_vector	plane_albedo(t_plane *lst_plane, int id_plane);

/*
** lst_square.c
*/
void		add_end_lst_square(t_square *new_square, t_obj *obj);
void		init_lst_square(char *line, t_obj *obj);
void		free_lst_square(t_obj *obj);
t_vector	square_albedo(t_square *lst_square, int id_square);

/*
** lst_cylinder.c
*/
void		add_end_lst_cylinder(t_cylinder *new_cylinder, t_obj *obj);
void		init_lst_cylinder(char *line, t_obj *obj);
void		free_lst_cylinder(t_obj *obj);
t_vector	cylinder_albedo(t_cylinder *lst_cylinder, int id_cylinder);

/*
** lst_triangle.c
*/
void		add_end_lst_triangle(t_triangle *new_triangle, t_obj *obj);
void		init_lst_triangle(char *line, t_obj *obj);
void		free_lst_triangle(t_obj *obj);
t_vector	triangle_albedo(t_triangle *lst_triangle, int id_triangle);

/*
** lst_cube.c
*/
void		init_lst_cube(char *line, t_obj *obj);

/*
** lst_pyramid.c
*/
void		init_lst_pyramid(char *line, t_obj *obj);

/*
** lst_cone.c
*/
void		add_end_lst_cone(t_cone *new_cone, t_obj *obj);
void		init_lst_cone(char *line, t_obj *obj);
void		free_lst_cone(t_obj *obj);
t_vector	cone_albedo(t_cone *lst_cone, int id_cone);

#endif
