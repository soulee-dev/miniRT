/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:34 by soulee            #+#    #+#             */
/*   Updated: 2023/05/28 16:21:36 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "scene.h"

void	add_sphere(t_scene *scene, char **strs)
{
	t_point3	center;
	double		radius;
	t_color		albedo;

	printf("Sphere\n");
	if (count_strings(strs) != 8)
		exit_error("error: Invalid file format");
	center = point3(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	radius = ft_atof(strs[4]);
	albedo = color(\
		ft_atoi(strs[5]), ft_atoi(strs[6]), ft_atoi(strs[7]));
	check_valid_vec3(albedo, 0, 255);
	add_obj(&scene->world, object(SP, sphere(center, radius), albedo));
	scene->count.sphere++;
}

void	add_plane(t_scene *scene, char **strs)
{
	t_point3	center;
	t_vec3		dir;
	t_color		albedo;

	printf("Plane\n");
	if (count_strings(strs) != 10)
		exit_error("error: Invalid file format");
	center = point3(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	dir = vec3(\
		ft_atof(strs[4]), ft_atof(strs[5]), ft_atof(strs[6]));
	check_valid_vec3(dir, -1.0, 1.0);
	albedo = color(\
		ft_atoi(strs[7]), ft_atoi(strs[8]), ft_atoi(strs[9]));
	check_valid_vec3(albedo, 0, 255);
	add_obj(&scene->world, object(PL, plane(center, unit_vector(dir)), albedo));
	scene->count.plane++;
}

void	add_cylinder(t_scene *scene, char **strs)
{
	t_point3	center;
	t_vec3		dir;
	double		diameter;
	double		height;
	t_color		albedo;

	printf("Cylinder\n");
	if (count_strings(strs) != 12)
		exit_error("error: Invalid file format");
	center = point3(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	dir = vec3(\
		ft_atof(strs[4]), ft_atof(strs[5]), ft_atof(strs[6]));
	check_valid_vec3(dir, -1.0, 1.0);
	diameter = ft_atof(strs[7]);
	height = ft_atof(strs[8]);
	albedo = color(\
		ft_atoi(strs[9]), ft_atoi(strs[10]), ft_atoi(strs[11]));
	add_obj(&scene->world, object(CY, cylinder(center, unit_vector(dir), \
		diameter, height), albedo));
	scene->count.cylinder++;
}
