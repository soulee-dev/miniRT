/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:54:38 by soulee            #+#    #+#             */
/*   Updated: 2023/05/04 16:37:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_img(t_env *env)
{
	env->img.aspect_ratio = 16.0 / 9.0;
	env->img.width = 200;
	env->img.height = (int)(env->img.width / env->img.aspect_ratio);
	env->img.samples_per_pixel = 50;
	env->img.max_depth = 10;
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

	t_texture		texture_ground;
	t_lambertian	lambertian_ground;
	material_ground.type = MATERIAL_LAMBERTIAN;
	texture_ground.type = TEXTURE_SOLID_COLOR;
	texture_ground.solid_color.color = create_vec3_xyz(0.8, 0.8, 0.0);
	lambertian_ground.albedo = texture_ground;
	material_ground.lambertian = lambertian_ground;

	t_texture		texture_center;
	t_lambertian	lambertian_center;
	material_center.type = MATERIAL_LAMBERTIAN;
	texture_center.type = TEXTURE_SOLID_COLOR;
	texture_center.solid_color.color = create_vec3_xyz(0.1, 0.2, 0.5);
	lambertian_center.albedo = texture_center;
	material_center.lambertian = lambertian_center;

	t_dielectric	dielectric_left;
	material_left.type = MATERIAL_DIELECTRIC;
	dielectric_left.ir = 1.5;
	material_left.dielectric = dielectric_left;

	t_metal	metal_right;
	material_right.type = MATERIAL_METAL;
	metal_right.albedo = create_vec3_xyz(0.8, 0.6, 0.2);
	metal_right.fuzz = 0.0;
	material_right.metal = metal_right;

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
