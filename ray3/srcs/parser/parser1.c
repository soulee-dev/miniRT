/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:36 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 18:57:53 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "scene.h"

void	add_ambient_light(t_scene *scene, char **strs)
{
	t_color	ambient;
	double	ka;

	if (count_strings(strs) != 5)
		exit_error("error: Invalid file format (Ambient Light)");
	if (scene->count.ambient_light)
		exit_error("error: Duplicated identifier (Ambient Light)");
	ka = ft_atof(strs[1]);
	check_valid(ka, 0.0, 1.0);
	ambient = color(ft_atoi(strs[2]), \
		ft_atoi(strs[3]), ft_atoi(strs[4]));
	check_valid_vec3(ambient, 0, 255);
	scene->ambient = mul_n_vec3(ambient, ka);
	scene->count.ambient_light++;
}

void	add_camera(t_scene *scene, char **strs)
{
	t_point3	lookfrom;
	t_point3	lookat;
	double		vfov;

	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format (Camera)");
	if (scene->count.camera)
		exit_error("error: Duplicated identifier (Camera)");
	lookfrom = point3(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	lookat = point3(\
		ft_atof(strs[4]), ft_atof(strs[5]), ft_atof(strs[6]));
	check_valid_vec3(lookat, -1.0, 1.0);
	vfov = ft_atoi(strs[7]);
	check_valid(vfov, 0, 180);
	scene->camera = camera(&scene->canvas, \
		lookfrom, unit_vector(lookat), vfov);
	scene->count.camera++;
}

void	add_light(t_scene *scene, char **strs)
{
	t_object	*lights;
	t_point3	orig;
	double		bright_ratio;
	t_color		light_color;

	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format (Light)");
	if (scene->count.light)
		exit_error("error: Duplicated identifier (Light)");
	orig = point3(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	bright_ratio = ft_atof(strs[4]);
	check_valid(bright_ratio, 0.0, 1.0);
	light_color = color(\
		ft_atoi(strs[5]), ft_atoi(strs[6]), ft_atoi(strs[7]));
	check_valid_vec3(light_color, 0, 255);
	lights = object(LIGHT_POINT, \
		light_point(orig, bright_ratio, light_color), color(0, 0, 0));
	scene->lights = lights;
	scene->count.light++;
}
