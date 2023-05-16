/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:14:26 by soulee            #+#    #+#             */
/*   Updated: 2023/05/16 19:45:40 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	add_plane(t_env *env, char **strs)
// {
    
// }

// void	add_cylinder(t_env *env, char **strs)
// {
    
// }

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
