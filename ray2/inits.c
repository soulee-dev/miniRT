/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:54:38 by soulee            #+#    #+#             */
/*   Updated: 2023/05/05 15:00:34 by soulee           ###   ########.fr       */
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
	t_texture	texture_ground;
	t_material	material_ground;

	texture_ground.type = TEXTURE_CHECKER;
	texture_ground.checker.even = create_vec3_xyz(0.2, 0.3, 0.1);
	texture_ground.checker.odd = create_vec3_t(0.9);
	material_ground.type = MATERIAL_LAMBERTIAN;
	material_ground.lambertian.albedo = texture_ground;
	env->world.size = 0;
	env->world.objects[env->world.size].type = SHAPE_SPHERE;
	env->world.objects[env->world.size].sphere.center = create_vec3_xyz(0, -1000, 0);
	env->world.objects[env->world.size].sphere.radius = 1000;
	env->world.objects[env->world.size].sphere.mat_ptr = material_ground;

	t_texture	texture_sphere;
	t_material	material_sphere;
	env->world.size++;
	texture_sphere.type = TEXTURE_SOLID_COLOR;
	texture_sphere.solid_color.color = create_vec3_xyz(255, 0, 0);
	material_sphere.type = MATERIAL_LAMBERTIAN;
	material_sphere.lambertian.albedo = texture_sphere;
	env->world.objects[env->world.size].type = SHAPE_SPHERE;
	env->world.objects[env->world.size].sphere.center = create_vec3_xyz(0, 2, 0);
	env->world.objects[env->world.size].sphere.radius = 2;
	env->world.objects[env->world.size].sphere.mat_ptr = material_sphere;

	t_material	material_light;
	env->world.size++;
	material_light.type = MATERIAL_DIFFUSE_LIGHT;
	material_light.diffuse_light.emit = create_vec3_xyz(4, 4, 4);
	env->world.objects[env->world.size].type = SHAPE_XY_RECT;
	env->world.objects[env->world.size].xy_rect.x0 = 3;
	env->world.objects[env->world.size].xy_rect.x1 = 5;
	env->world.objects[env->world.size].xy_rect.y0 = 1;
	env->world.objects[env->world.size].xy_rect.y1 = 3;
	env->world.objects[env->world.size].xy_rect.k = -2;
	env->world.objects[env->world.size].xy_rect.mat_ptr = material_light;
}
