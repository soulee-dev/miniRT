/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:14:10 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 12:41:09 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define TITLE	"miniRT-practice"

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
	t_point3	orig;
	t_vec3		dir;
	double		time;
}				t_ray;

// Camera
typedef struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
}				t_camera;

// Canvas
typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}				t_canvas;

// Sphere
typedef struct s_sphere
{
	t_point3	center;
	double		radius;
}				t_sphere;

// camera.c
t_camera	camera(t_canvas *canvas, t_point3 orig);

// cnavas.c
t_canvas	canvas(int width, int height);

// utils/random1.c
double		random_double(void);
double		random_double2(double min, double max);
t_vec3		random_vec3(void);
t_vec3		random_vec3_2(double min, double max);
t_vec3		random_in_unit_sphere(void);

// utils/random2.c
t_vec3		random_unit_vector(void);
t_vec3		random_in_hemisphere(t_vec3 normal);
int			random_int(int min, int max);

// utils/math1.c
double		length_squared(t_vec3 u);
double		length(t_vec3 u);
double		clamp(double x, double min, double max);
double		degrees_to_radians(double degrees);

// utils/vec1.c
t_vec3		add_vec3(t_vec3 u, t_vec3 v);
t_vec3		mul_n_vec3(t_vec3 u, double t);
t_vec3		mul_vec3(t_vec3 u, t_vec3 v);
double		dot(t_vec3 u, t_vec3 v);
t_vec3		sub_vec3(t_vec3 u, t_vec3 v);

// utils/vec2.c
t_vec3		div_n_vec3(t_vec3 u, double t);
t_vec3		unit_vector(t_vec3 u);
t_vec3		at(t_ray r, double t);
t_vec3		vec3(double x, double y, double z);
t_color		color(double x, double y, double z);
t_point3	point3(double x, double y, double z);

// utils/vec3.c
void		print_vec3(t_vec3 vec3);
int			near_zero(t_vec3 u);
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_vec3		refract(t_vec3 uv, t_vec3 n, double etai_over_etat);
t_vec3		cross(t_vec3 u, t_vec3 v);

// utils/vec4.c
t_vec3		random_in_unit_disk(void);
double		nth_vec3(t_vec3 u, int n);
t_vec3		min_vec3(t_vec3 u, t_vec3 v);

// utils/ray1.c
t_ray		ray(t_point3 orig, t_vec3 dir);

// render.c
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color		ray_color(t_ray *r);
void	render(t_canvas *canv, t_camera *cam, void *mlx, void *mlx_win);

#endif