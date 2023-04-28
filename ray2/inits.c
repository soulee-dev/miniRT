/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:54:38 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 23:37:10 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_img(t_env *env)
{
	env->img.aspect_ratio = 16.0 / 9.0;
	env->img.width = 400;
	env->img.height = env->img.width / env->img.aspect_ratio;
	env->img.samples_per_pixel = 100;
	env->img.max_depth = 50;
}

void	init_mlx(t_env *env)
{
	env->mlx.mlx = mlx_init();
	env->mlx.win = mlx_new_window(env->mlx.mlx, env->img.width,
			env->img.height, TITLE);
}

void	init_cam(t_env *env)
{
	env->cam.viewport_height = 4.0;
	env->cam.viewport_width = env->img.aspect_ratio * env->cam.viewport_height;
	env->cam.focal_length = 1.0;
}

void	init_cam_vec3(t_env *env)
{
	t_vec3	u;

	env->cam.origin.x = 0.0;
	env->cam.origin.y = 0.0;
	env->cam.origin.z = 0.0;
	env->cam.horizontal.x = env->cam.viewport_width;
	env->cam.horizontal.y = 0.0;
	env->cam.horizontal.z = 0.0;
	env->cam.vertical.x = 0.0;
	env->cam.vertical.y = env->cam.viewport_height;
	env->cam.vertical.z = 0.0;
	u.x = 0.0;
	u.y = 0.0;
	u.z = env->cam.focal_length;
	env->cam.lower_left_corner = sub_vec3(env->cam.origin,
			add_vec3(add_vec3(div_n_vec3(env->cam.horizontal, 2),
					div_n_vec3(env->cam.vertical, 2)), u));
}

void	init_world(t_env *env)
{
	env->world.objects[0].type = TYPE_SPHERE;
	env->world.objects[0].sphere.center = create_vec3_xyz(0, 0, -1);
	env->world.objects[0].sphere.radius = 0.5;

	env->world.objects[1].type = TYPE_SPHERE;
	env->world.objects[1].sphere.center = create_vec3_xyz(0, -100.5, -1);
	env->world.objects[1].sphere.radius = 100;

	env->world.size = 2;
}
