/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:43:56 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 20:05:09 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	add_ambient_light(t_env *env, char **strs)
// {
// 	;
// }

void	add_camera(t_env *env, char **strs)
{
	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format (Camera)");
	if (env->cam_env.flag)
		exit_error("error: Camera already setted");
	env->cam_env.lookfrom = create_vec3_xyz(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	env->cam_env.lookat = create_vec3_xyz(\
		ft_atoi(strs[4]), ft_atoi(strs[5]), ft_atoi(strs[6]));
	env->cam_env.vfov = ft_atoi(strs[7]);
	check_valid_vec3(env->cam_env.lookat, -1, 1);
	check_valid(env->cam_env.vfov, 0, 180);
	env->cam_env.vup = create_vec3_xyz(0, 1, 0);
	env->cam_env.aspect_ratio = env->img.aspect_ratio;
	env->cam_env.aperture = 0.1;
	env->cam_env.dist_to_focus = 10.0;
	env->cam_env.time0 = 0.0;
	env->cam_env.time1 = 1.0;
}

void	add_light(t_env *env, char **strs)
{
	double		brightness;
	t_color		color;
	t_material	material_light;

	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format (Light)");
	material_light.type = MATERIAL_DIFFUSE_LIGHT;
	brightness = ft_atof(strs[4]);
	check_valid(brightness, 0, 1);
	color = create_vec3_xyz(\
		ft_atoi(strs[5]), ft_atoi(strs[6]), ft_atoi(strs[7]));
	check_valid_vec3(color, 0, 255);
	material_light.diffuse_light.emit = mul_n_vec3(color, brightness);
	env->world.objects[env->world.size].type = SHAPE_SPHERE;
	env->world.objects[env->world.size].sphere.center = create_vec3_xyz(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atoi(strs[3]));
	env->world.objects[env->world.size].sphere.radius = 1;
	env->world.objects[env->world.size].sphere.mat_ptr = material_light;
	env->world.size++;
}

void	add_sphere(t_env *env, char **strs)
{
	t_texture	texture_sphere;
	t_material	material_sphere;

	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format (Sphere)");
	env->world.objects[env->world.size].type = SHAPE_SPHERE;
	env->world.objects[env->world.size].sphere.center = create_vec3_xyz(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	env->world.objects[env->world.size].sphere.radius = ft_atof(strs[4]);
	texture_sphere.type = TEXTURE_SOLID_COLOR;
	texture_sphere.solid_color.color = create_vec3_xyz(\
		ft_atof(strs[5]), ft_atof(strs[6]), ft_atof(strs[7]));
	check_valid_vec3(texture_sphere.solid_color.color, 0, 255);
	material_sphere.type = MATERIAL_LAMBERTIAN;
	material_sphere.lambertian.albedo = texture_sphere;
	env->world.objects[env->world.size].sphere.mat_ptr = material_sphere;
	env->world.size++;
}
