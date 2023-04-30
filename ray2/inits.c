/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:54:38 by soulee            #+#    #+#             */
/*   Updated: 2023/04/30 13:34:44 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_img(t_env *env)
{
	env->img.aspect_ratio = 3.0 / 2.0;
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
	t_material	material_ground;
	t_material	material_center;
	t_material	material_left;
	t_material	material_right;

	material_ground.type = MATERIAL_LAMBERTIAN;
	material_ground.albedo = create_vec3_xyz(0.8, 0.8, 0.0);

	material_center.type = MATERIAL_LAMBERTIAN;
	material_center.albedo = create_vec3_xyz(0.1, 0.2, 0.5);

	material_left.type = MATERIAL_DIELECTRIC;
	material_left.ir = 1.5;

	material_right.type = MATERIAL_METAL;
	material_right.albedo = create_vec3_xyz(0.8, 0.6, 0.2);
	material_right.fuzz = 0.0;

	env->world.objects[0].type = SHAPE_SPHERE;
	env->world.objects[0].sphere.center = create_vec3_xyz(0.0, -100.5, -1.0);
	env->world.objects[0].sphere.radius = 100;
	env->world.objects[0].sphere.mat_ptr = material_ground;

	env->world.objects[1].type = SHAPE_SPHERE;
	env->world.objects[1].sphere.center = create_vec3_xyz(0.0, 0.0, -1.0);
	env->world.objects[1].sphere.radius = 0.5;
	env->world.objects[1].sphere.mat_ptr = material_center;

	env->world.objects[2].type = SHAPE_SPHERE;
	env->world.objects[2].sphere.center = create_vec3_xyz(-1.0, 0.0, -1.0);
	env->world.objects[2].sphere.radius = 0.5;
	env->world.objects[2].sphere.mat_ptr = material_left;

	env->world.objects[3].type = SHAPE_SPHERE;
	env->world.objects[3].sphere.center = create_vec3_xyz(-1.0, 0.0, -1.0);
	env->world.objects[3].sphere.radius = -0.45;
	env->world.objects[3].sphere.mat_ptr = material_left;

	env->world.objects[4].type = SHAPE_SPHERE;
	env->world.objects[4].sphere.center = create_vec3_xyz(1.0, 0.0, -1.0);
	env->world.objects[4].sphere.radius = 0.5;
	env->world.objects[4].sphere.mat_ptr = material_right;

	env->world.size = 5;
}
