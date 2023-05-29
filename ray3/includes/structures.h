/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:46:22 by soulee            #+#    #+#             */
/*   Updated: 2023/05/29 18:08:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdio.h>

# define TITLE "miniRT"
# define CODE_SIZE 256
# define EPSILON 1e-6
# define LUMEN 3
# define CAM_NORMAL_RATIO 50

typedef enum e_event
{
	KEYDOWN = 2,
	KEYUP = 3,
	DESTROY = 17
}			t_event;

typedef enum e_key
{
	KEY_ESC = 53,
	KEY_Q = 12,
	KEY_R = 14,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ARROW_UP = 126,
	KEY_ARROW_DOWN = 125,
	KEY_ARROW_LEFT = 123,
	KEY_ARROW_RIGHT = 124
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
	int				is_rendered;
	t_point3		lookfrom;
	t_point3		lookat;
	double			vfov;
}				t_scene;

typedef struct s_phong_light
{
	t_color	diffuse;
	t_vec3	light_dir;
	double	kd;
	t_color	specular;
	double	light_len;
	t_ray	light_ray;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;
	double	ksn;
	double	ks;
	double	brightness;
}				t_phong_light;

typedef struct s_discriminant
{
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	t_vec3		delta_p;
	t_vec3		u;
	t_vec3		o;
}				t_discriminant;
#endif