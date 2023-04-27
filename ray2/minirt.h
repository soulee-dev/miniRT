/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:59:16 by soulee            #+#    #+#             */
/*   Updated: 2023/04/27 16:59:35 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// Define
# define WIDTH	1920
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
	double	viewport_height;
	double	viewport_width;
	double	focal_lenght;
}				t_cam;

// Environment
typedef struct s_env
{
	t_mlx	mlx;
	t_img	img;
	t_cam	cam;
}				t_env;
#endif