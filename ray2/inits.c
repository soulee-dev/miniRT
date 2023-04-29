/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:54:38 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 23:48:36 by soulee           ###   ########.fr       */
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

void	init_world(t_env *env)
{
	double	r;
	t_material	material_left;
	t_material	material_right;

	r = cos(PI / 4);
	material_left.type = MATERIAL_LAMBERTIAN;
	material_left.albedo = create_vec3_xyz(0, 0, 1);

	material_right.type = MATERIAL_LAMBERTIAN;
	material_right.albedo = create_vec3_xyz(1, 0, 0);

	env->world.objects[0].type = SHAPE_SPHERE;
	env->world.objects[0].sphere.center = create_vec3_xyz(-r, 0, -1);
	env->world.objects[0].sphere.radius = r;
	env->world.objects[0].sphere.mat_ptr = material_left;

	env->world.objects[1].type = SHAPE_SPHERE;
	env->world.objects[1].sphere.center = create_vec3_xyz(r, 0, -1);
	env->world.objects[1].sphere.radius = r;
	env->world.objects[1].sphere.mat_ptr = material_right;

	env->world.size = 2;
}
