/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:59:16 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 23:37:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// Define
# define TITLE	"miniRT-practice"

enum e_keys {
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ARROW_UP = 126,
	KEY_ARROW_DOWN = 125,
	X_EVENT_KEY_RELEASE = 3,
	X_EVENT_KEY_EXIT = 17
};

enum e_type {
	TYPE_SPHERE = 1
};

// Vector
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef t_vec3	t_point3;
typedef t_vec3	t_color;

// Ray
typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}				t_ray;

// Sphere
typedef struct s_sphere
{
	t_point3	center;
	double		radius;
}				t_sphere;

// Hit Records
typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		t;
	int			front_face;
}				t_hit_record;

typedef struct s_shape
{
	int			type;
	t_sphere	sphere;
}				t_shape;

typedef struct s_hittable_list
{
	// Originally, objects is shared ptr of hittable
	t_shape	objects[2];
	size_t	size;
}				t_hittable_list;

// Mlx
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

// Image
typedef struct s_img
{
	double	aspect_ratio;
	int		width;
	int		height;
	int		samples_per_pixel;
	int		max_depth;
}				t_img;

// Camera
typedef struct s_cam
{
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_vec3	origin;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	lower_left_corner;
}				t_cam;

// Environment
typedef struct s_env
{
	t_mlx			mlx;
	t_img			img;
	t_cam			cam;
	t_hittable_list	world;
}				t_env;

// render.c
void	render(t_env *env);

// math_utils1.c
double	length_squared(t_vec3 u);
double	length(t_vec3 u);
double	clamp(double x, double min, double max);

// vec3_utils1.c
t_vec3	add_vec3(t_vec3 u, t_vec3 v);
t_vec3	mul_n_vec3(t_vec3 u, double t);
t_vec3	mul_vec3(t_vec3 u, t_vec3 v);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	sub_vec3(t_vec3 u, t_vec3 v);

// vec3_utils2.c
t_vec3	div_n_vec3(t_vec3 u, double t);
t_vec3	unit_vector(t_vec3 u);
t_vec3	at(t_vec3 origin, t_vec3 dir, double t);
t_vec3	create_vec3_t(double t);
t_vec3	create_vec3_xyz(double x, double y, double z);

// vec3_utils3.c
void	print_vec3(t_vec3 vec3);

// inits.c
void	init_img(t_env *env);
void	init_mlx(t_env *env);
void	init_cam(t_env *env);
void	init_cam_vec3(t_env *env);
void	init_world(t_env *env);

// sphere.c
double	sphere_hit(t_ray *r, double t_min, double t_max,
			t_hit_record *rec, t_sphere sphere);

// hit_record.c
void	set_face_normal(t_hit_record *hit_record,
			t_ray *r, t_vec3 *outward_normal);

// hittable_list.c
int		hittable_list_hit(t_hittable_list list, t_ray *r,
			double t_min, double t_max, t_hit_record *rec);

// camera.c
t_ray	camera_get_ray(t_env *env, double u, double v);

// REMOVE BEFORE FLIGHT
double	random_double(void);
double	random_double2(double min, double max);
t_vec3	random_vec3(void);
t_vec3	random_vec3_2(double min, double max);
t_vec3	random_in_unit_sphere(void);
t_vec3	random_unit_vector(void);
// REMOVE BEFORE FLIGHT

#endif