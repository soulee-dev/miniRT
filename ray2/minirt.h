/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:59:16 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 16:34:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// Define
# define WIDTH	1080
# define TITLE	"miniRT-practice"

enum e_keys{
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
	t_mlx	mlx;
	t_img	img;
	t_cam	cam;
}				t_env;

// render.c
void	render(t_env *env);

// math_utils1.c
double	length_squared(t_vec3 u);
double	length(t_vec3 u);

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

// inits.c
void	init_img(t_env *env);
void	init_mlx(t_env *env);
void	init_cam(t_env *env);
void	init_cam_vec3(t_env *env);

#endif