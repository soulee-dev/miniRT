/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:43:56 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 16:53:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_atof(char *str)
{
	return ((double)ft_atoi(str));
}

void	add_ambient_light(t_env *env, char **strs)
{
	;
}

void	add_camera(t_env *env, char **strs)
{
	// Should check there is more than one camera in map.
	t_cam_env	cam_env;

	cam_env.lookfrom = create_vec3_xyz();
}

void	add_sphere(t_env *env, char **strs)
{
	// should add atoi for double;
	t_texture	texture_sphere;
	t_material	material_sphere;

	texture_sphere.type = TEXTURE_SOLID_COLOR;
	texture_sphere.solid_color.color = create_vec3_xyz();

}

void	add_plane(t_env *env, char **strs)
{
    
}

void	add_cylinder(t_env *env, char **strs)
{
    
}
