/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:46:22 by soulee            #+#    #+#             */
/*   Updated: 2023/05/25 22:07:59 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define TITLE "miniRT"
# define CODE_SIZE 256
# define EPSILON 1e-6
# define LUMEN 3

typedef enum e_event
{
	KEYDOWN = 2,
	KEYUP = 3,
	DESTROY = 17
}			t_even;

typedef enum e_key
{
	KEY_ESC = 53,
	KEY_Q = 12
}			t_key;

typedef enum e_object_type
{
	SP = 1,
	CY = 2,
	PL = 3,
	LIGHT_POINT = 4
}		t_objet_type;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef t_vec3	t_point3;
typedef t_vec3	t_color;

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
	double		time;
}				t_ray;

typedef struct s_camera
{
	t_point3	orig;
	t_point3	lower_left_corner;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
}				t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}				t_canvas;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
}				t_sphere;

typedef struct s_cylinder
{
	t_point3	center;
	t_vec3		dir;
	double		diameter;
	double		height;
}				t_cylinder;

typedef struct s_plane
{
	t_point3	center;
	t_vec3		dir;
}				t_plane;

typedef struct s_light
{
	t_point3	orig;
	t_color		light_color;
	double		bright_ratio;
}				t_light;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	int			front_face;
	t_color		albedo;
}				t_hit_record;

typedef struct s_object
{
	int		type;
	void	*element;
	t_color	albedo;
	void	*next;
}			t_object;

typedef struct s_count
{
	size_t	ambient_light;
	size_t	camera;
	size_t	light;
	size_t	sphere;
	size_t	plane;
	size_t	cylinder;
}				t_count;

typedef struct s_scene
{
	void			*mlx;
	void			*mlx_win;
	t_count			count;
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*lights;
	t_color			ambient;
	t_ray			ray;
	t_hit_record	rec;
}				t_scene;
#endif