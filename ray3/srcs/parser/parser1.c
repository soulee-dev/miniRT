/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:36 by soulee            #+#    #+#             */
/*   Updated: 2023/05/29 17:44:23 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "scene.h"

void	add_ambient_light(t_scene *scene, char **strs)
{
	t_color	ambient;
	double	ka;

	printf("Ambient Light\n");
	if (count_strings(strs) != 5)
		exit_error("error: Invalid file format");
	if (scene->count.ambient_light)
		exit_error("error: Duplicated identifier");
	ka = ft_atof(strs[1]);
	check_valid(ka, 0.0, 1.0);
	ambient = color(ft_atoi(strs[2]), \
		ft_atoi(strs[3]), ft_atoi(strs[4]));
	check_valid_vec3(ambient, 0, 255);
	ambient = div_n_vec3(ambient, 255);
	scene->ambient = mul_n_vec3(ambient, ka);
	scene->count.ambient_light++;
}

void	add_camera(t_scene *scene, char **strs)
{
	t_point3	lookfrom;
	t_point3	lookat;
	double		vfov;

	printf("Camera\n");
	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format");
	if (scene->count.camera)
		exit_error("error: Duplicated identifier");
	lookfrom = point3(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	lookat = point3(\
		ft_atof(strs[4]), ft_atof(strs[5]), ft_atof(strs[6]));
	check_valid_vec3(lookat, -1.0, 1.0);
	vfov = ft_atoi(strs[7]);
	check_valid(vfov, 0, 180);
	lookat = mul_n_vec3(lookat, CAM_NORMAL_RATIO);
	scene->camera = camera(&scene->canvas, \
		lookfrom, lookat, vfov);
	scene->lookfrom = lookfrom;
	scene->lookat = lookat;
	scene->vfov = vfov;
	scene->count.camera++;
}

void	add_light(t_scene *scene, char **strs)
{
	t_object	*lights;
	t_point3	orig;
	double		bright_ratio;
	t_color		light_color;

	printf("Light\n");
	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format");
	if (scene->count.light)
		exit_error("error: Duplicated identifier");
	orig = point3(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	bright_ratio = ft_atof(strs[4]);
	check_valid(bright_ratio, 0.0, 1.0);
	light_color = color(\
		ft_atoi(strs[5]), ft_atoi(strs[6]), ft_atoi(strs[7]));
	check_valid_vec3(light_color, 0, 255);
	light_color = div_n_vec3(light_color, 255);
	lights = object(LIGHT_POINT, \
		light_point(orig, bright_ratio, light_color), color(0, 0, 0));
	scene->lights = lights;
	scene->count.light++;
}
