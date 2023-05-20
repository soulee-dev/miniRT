/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:46:22 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 12:51:38 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
}				t_sphere;


#endif