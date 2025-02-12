/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:50:41 by anclarma          #+#    #+#             */
/*   Updated: 2021/03/21 11:03:57 by pompier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_color		t_color;
struct			s_color
{
	char		depth;
	char		r;
	char		g;
	char		b;
};
typedef struct s_vector		t_vector;
struct			s_vector
{
	double		x;
	double		y;
	double		z;
};
typedef struct s_ray		t_ray;
struct			s_ray
{
	t_vector	coord;
	t_vector	normal;
};
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
	t_vector	rot;
	int			fov;
	double		fov_rad;
	char		*parameter;
	int			id;
	t_cam		*next;
};
typedef struct s_light		t_light;
struct			s_light
{
	t_vector	coord;
	double		ratio;
	t_color		color;
	t_light		*next;
};
typedef struct s_sphere		t_sphere;
struct			s_sphere
{
	t_vector	coord;
	double		diameter;
	double		radius2;
	t_color		color;
	char		*parameter;
	t_sphere	*next;
};
typedef struct s_plane		t_plane;
struct			s_plane
{
	t_vector	coord;
	t_vector	normal;
	t_color		color;
	t_plane		*next;
};
typedef struct s_square		t_square;
struct			s_square
{
	t_vector	coord;
	t_vector	normal;
	double		side;
	t_color		color;
	t_square	*next;
};
typedef struct s_cylinder	t_cylinder;
struct			s_cylinder
{
	t_vector	coord;
	t_vector	normal;
	t_color		color;
	double		diameter;
	double		radius2;
	double		height;
	t_cylinder	*next;
};
typedef struct s_triangle	t_triangle;
struct			s_triangle
{
	t_vector	coord1;
	t_vector	coord2;
	t_vector	coord3;
	t_vector	edge1;
	t_vector	edge2;
	t_color		color;
	t_triangle	*next;
};
typedef struct s_cone		t_cone;
struct			s_cone
{
	t_vector	coord;
	t_vector	normal;
	double		diameter;
	double		height;
	t_color		color;
	t_cone		*next;
};
typedef struct s_obj		t_obj;
struct			s_obj
{
	t_res		*res;
	t_amb_light	*amb_light;
	t_cam		*current_cam;
	t_cam		*lst_cam;
	t_light		*lst_light;
	t_sphere	*lst_sphere;
	t_plane		*lst_plane;
	t_square	*lst_square;
	t_cylinder	*lst_cylinder;
	t_triangle	*lst_triangle;
	t_cone		*lst_cone;
	double		intensite_lumiere;
};
typedef struct s_mlx		t_mlx;
struct			s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*image;
	int			x_size;
	int			y_size;
	int			x_save;
	int			y_save;
	int			size_line;
	int			bpp;
	int			endian;
	int			*aa_image;
	int			*iaa_image;
	int			aa;
	int			iaa;
	int			x_size_aa;
	int			y_size_aa;
	int			x_size_iaa;
	int			y_size_iaa;
	t_obj		*obj;
};

typedef struct s_arg		t_arg;
struct			s_arg
{
	t_mlx		*mlx;
	int			y_min;
	int			y_max;
};
typedef struct s_check		t_check;
struct			s_check
{
	int			id_cat;
	int			id_obj;
	double		min_t;
	double		t;
	t_ray		ray;
	t_vector	p;
	t_vector	n;
	t_obj		*obj;
	t_light		*light;
};
typedef struct s_calc		t_calc;
struct			s_calc
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t1;
	double		t2;
	t_vector	u;
	t_vector	v;
};
typedef struct s_calc_t		t_calc_t;
struct			s_calc_t
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	h;
	t_vector	s;
	t_vector	q;
	double		a;
	double		f;
	double		u;
	double		v;
};

#endif
