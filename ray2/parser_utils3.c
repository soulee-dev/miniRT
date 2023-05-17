/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:14:26 by soulee            #+#    #+#             */
/*   Updated: 2023/05/17 15:59:26 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	add_plane(t_env *env, char **strs)
// {
    
// }

void	add_cylinder(t_env *env, char **strs)
{
	t_texture	texture_cylinder;
	t_material	material_cylinder;

	if (count_strings(strs) != 12)
		exit_error("error: Invalid file format (Cylinder)");
	env->world.objects[env->world.size].type = SHAPE_CYLINDER;
	env->world.objects[env->world.size].cylinder.center = create_vec3_xyz(\
		ft_atof(strs[1]), ft_atof(strs[2]), ft_atof(strs[3]));
	env->world.objects[env->world.size].cylinder.direction = create_vec3_xyz(\
		ft_atof(strs[4]), ft_atof(strs[5]), ft_atof(strs[6]));
	check_valid_vec3(env->world.objects[env->world.size].cylinder.direction,\
		-1, 1);
	env->world.objects[env->world.size].cylinder.diameter = ft_atof(strs[7]);
	env->world.objects[env->world.size].cylinder.height = ft_atof(strs[8]);
	texture_cylinder.type = TEXTURE_SOLID_COLOR;
	texture_cylinder.solid_color.color = create_vec3_xyz(\
		ft_atof(strs[9]), ft_atof(strs[10]), ft_atof(strs[11]));
	check_valid_vec3(texture_cylinder.solid_color.color, 0, 255);
	material_cylinder.type = MATERIAL_LAMBERTIAN;
	material_cylinder.lambertian.albedo = texture_cylinder;
	env->world.objects[env->world.size].cylinder.mat_ptr = material_cylinder;
	env->world.size++;
}

void	check_valid(double val, double min, double max)
{
	if (!(val >= min && val <= max))
		exit_error("error: Value not in range");
}

void	check_valid_vec3(t_vec3 vec3, double min, double max)
{
	check_valid(vec3.x, min, max);
	check_valid(vec3.y, min, max);
	check_valid(vec3.z, min, max);
}
