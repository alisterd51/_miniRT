/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:50:41 by anclarma          #+#    #+#             */
/*   Updated: 2020/10/16 16:23:57 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_res		t_res;
struct			s_res
{
	int			x_size;
	int			y_size;
};
typedef struct s_amb_light	t_amb_light;
struct			s_amb_light
{
	double		ratio;
	t_color		color;
};
typedef struct s_cam		t_cam;
struct			s_cam
{
	t_vector	coord;
	t_vector	normal;
	int			fov;
	char		*parameter;
	t_cam		*next;
};
typedef struct s_light		t_light;
struct			s_light
{
};
typedef struct s_obj		t_obj;
struct			s_obj
{
	t_res		res;
	t_amb_light	amb_light;
	t_cam		*lst_cam;
	t_light		*lst_light;
	t_sphere	*lst_sphere;
	t_plane		*lst_plane;
	t_square	*lst_square;
	t_cylinder	*lst_cylinder;
	t_triangle	*lst_triangle;
	t_cone		*lst_cone;
};

#endif
