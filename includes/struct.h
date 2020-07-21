/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:06:52 by anclarma          #+#    #+#             */
/*   Updated: 2020/07/21 16:31:32 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pos	t_pos;
struct			s_pos
{
	double		x;
	double		y;
	double		z;
};
typedef struct s_vector	t_vector;
struct			s_vector
{
	double		x;
	double		y;
	double		z;
};
typedef struct s_res	t_res;
struct			s_res
{
	int			x_size;
	int			y_size;
};
typedef struct s_amblight	t_amblight;
struct			s_amblight
{
	double		ratio;
	int			color;
};
typedef struct s_camera	t_camera;
struct			s_camera
{
	int			id;
	t_vector	c;
	t_vector	vec;
	int			fov;
	t_camera	*next;
};
typedef struct s_light	t_light;
struct			s_light
{
	int			id;
	t_vector	c;
	double		ratio;
	int			color;
	t_light		*next;
};
typedef struct s_sphere	t_sphere;
struct			s_sphere
{
	int			id;
	t_vector	c;
	double		radius;
	int			color;
	int			mirror;
	int			transp;
	t_sphere	*next;
};
typedef struct s_plane	t_plane;
struct			s_plane
{
	int			id;
	t_vector	c;
	t_vector	o;
	int			color;
	t_plane		*next;
};
typedef struct s_square	t_square;
struct			s_square
{
	int			id;
	t_vector	c;
	t_vector	o;
	double		height;
	int			color;
	t_square	*next;
};
typedef struct s_cylinder	t_cylinder;
struct			s_cylinder
{
	int			id;
	t_vector	c;
	t_vector	o;
	double		radius;
	double		height;
	int			color;
	t_cylinder	*next;
};
typedef struct s_triangle	t_triangle;
struct			s_triangle
{
	int			id;
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	int			color;
	t_triangle	*next;
};
typedef struct s_ray	t_ray;
struct			s_ray
{
	t_vector	o;
	t_vector	d;
};
typedef struct s_obj	t_obj;
struct			s_obj
{
	t_res		*resolution;
	t_amblight	*amblight;
	t_camera	*lst_cam;
	t_light		*lst_light;
	int			intensite_lumiere;
	t_sphere	*lst_sphere;
	t_plane		*lst_plane;
	t_square	*lst_square;
	t_cylinder	*lst_cylinder;
	t_triangle	*lst_triangle;
};
typedef struct s_mlx	t_mlx;
struct			s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*image;
	int			width;
	int			height;
	int			**pixel;
	int			size_line;
	int			bpp;
	int			endian;
	t_obj		obj;
};
typedef struct s_arg	t_arg;
struct			s_arg
{
	t_mlx		*mlx;
	int			y_min;
	int			y_max;
};
typedef struct s_check_scene	t_check_scene;
struct			s_check_scene
{
	t_obj		scene;
	t_ray		ray;
	t_vector	p;
	t_vector	n;
	int			obj_id[2];
	double		t;
	double		min_t;
};
typedef struct s_local	t_local;
struct			s_local
{
	int			has_inter;
	double		t;
	t_vector	p;
	t_vector	n;
};
#endif
