/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:59:16 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 12:45:40 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// REMOVE BEFORE FLIGHT
# include "progress/progress.h"
// REMOVE BEFORE FLIGHT
# include "mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// Define
# define PI 3.1415926535897932385
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

enum e_shapes {
	SHAPE_SPHERE = 1,
	SHAPE_MOVING_SPHERE = 2
};

enum e_materials {
	MATERIAL_LAMBERTIAN = 1,
	MATERIAL_METAL = 2,
	MATERIAL_DIELECTRIC = 3
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
	double		time;
}				t_ray;

typedef struct s_material
{
	int		type;
	t_color	albedo;
	double	fuzz;
	double	ir;
}				t_material;

// Shapes
typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	t_material	mat_ptr;
}				t_sphere;

typedef struct s_moving_sphere
{
	t_point3	center0;
	t_point3	center1;
	double		time0;
	double		time1;
	double		radius;
	t_material	mat_ptr;
}				t_moving_sphere;

// Hit Records
typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	t_material	mat_ptr;
	double		t;
	int			front_face;
}				t_hit_record;

typedef struct s_shape
{
	int				type;
	t_sphere		sphere;
	t_moving_sphere	moving_sphere;
}				t_shape;

typedef struct s_aabb
{
	t_point3	minimum;
	t_point3	maximum;
}				t_aabb;

typedef struct s_hittable_list
{
	// Originally, objects is shared ptr of hittable
	t_shape	objects[1024];
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
	t_vec3	origin;
	t_vec3	lower_left_corner;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	double	time0;
	double	time1;
	double	lense_radius;
}				t_cam;

// Environment
typedef struct s_env
{
	t_mlx			mlx;
	t_img			img;
	t_hittable_list	world;
}				t_env;

// render.c
void	render(t_env *env, t_cam cam);

// math1.c
double	length_squared(t_vec3 u);
double	length(t_vec3 u);
double	clamp(double x, double min, double max);
double	degrees_to_radians(double degrees);

// vec1.c
t_vec3	add_vec3(t_vec3 u, t_vec3 v);
t_vec3	mul_n_vec3(t_vec3 u, double t);
t_vec3	mul_vec3(t_vec3 u, t_vec3 v);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	sub_vec3(t_vec3 u, t_vec3 v);

// vec2.c
t_vec3	div_n_vec3(t_vec3 u, double t);
t_vec3	unit_vector(t_vec3 u);
t_vec3	at(t_ray r, double t);
t_vec3	create_vec3_t(double t);
t_vec3	create_vec3_xyz(double x, double y, double z);

// vec3.c
void	print_vec3(t_vec3 vec3);
int		near_zero(t_vec3 u);
t_vec3	reflect(t_vec3 v, t_vec3 n);
t_vec3	refract(t_vec3 uv, t_vec3 n, double etai_over_etat);
t_vec3	cross(t_vec3 u, t_vec3 v);

// vec4.c
t_vec3	random_in_unit_disk(void);
double	nth_vec3(t_vec3 u, int n);

// inits.c
void	init_img(t_env *env);
void	init_mlx(t_env *env);
void	init_world(t_env *env);

// Shapes
int		sphere_hit(t_ray *r, double t_min, double t_max, \
			t_hit_record *rec, t_sphere sphere);

int		moving_sphere_hit(t_ray *r, double t_min, double t_max, \
			t_hit_record *rec, t_moving_sphere moving_sphere);

// hit_record.c
void	set_face_normal(t_hit_record *rec, \
	t_ray *r, t_vec3 *outward_normal);

// hittable_list.c
int		hittable_list_hit(t_hittable_list list, t_ray *r,
			double t_min, double t_max, t_hit_record *rec);

// camera.c
t_cam	init_camera(t_point3 lookfrom, t_point3 lookat, t_vec3 vup, \
			double vfov, double aspect_ratio, double aperture, \
				double focus_dist, double _time0, double _time1);
t_ray	camera_get_ray(t_cam cam, double u, double v);

// materials
int		lambertian_scatter(t_ray *r_in, t_hit_record *rec,
			t_color *attenuation, t_ray *scattered, t_material material);
int		metal_scatter(t_ray *r_in, t_hit_record *rec,
			t_color *attenuation, t_ray *scattered, t_material material);
int		dielectric_scatter(t_ray *r_in, t_hit_record *rec,
			t_color *attenuation, t_ray *scattered, t_material material);

// random1
double	random_double(void);
double	random_double2(double min, double max);
t_vec3	random_vec3(void);
t_vec3	random_vec3_2(double min, double max);
t_vec3	random_in_unit_sphere(void);

// random2
t_vec3	random_unit_vector(void);
t_vec3	random_in_hemisphere(t_vec3 normal);


// REMOVE BEFORE FLIGHT
t_hittable_list random_scene(void);
// REMOVE BEFORE FLIGHT

#endif