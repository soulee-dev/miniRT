/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:11:17 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 22:13:14 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	camera_get_ray(t_env *env, double u, double v)
{
	t_ray	ray;

	ray.origin = env->cam.origin;
	ray.direction = add_vec3(env->cam.lower_left_corner,
			add_vec3(mul_n_vec3(env->cam.horizontal, u),
				mul_n_vec3(sub_vec3(env->cam.vertical,
						env->cam.origin), v)));
	return (ray);
}
