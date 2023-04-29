/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:11:17 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 23:48:11 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	init_camera(double vfov, double aspect_ratio)
{
	t_vec3	u;
	t_cam	cam;

	cam.theta = degrees_to_radians(vfov);
	cam.h = tan(cam.theta / 2);
	cam.viewport_height = 2.0 * cam.h;
	cam.viewport_width = aspect_ratio * cam.viewport_height;
	cam.focal_length = 1.0;
	cam.origin = create_vec3_t(0.0);
	cam.horizontal = create_vec3_xyz(cam.viewport_width, 0, 0);
	cam.vertical = create_vec3_xyz(0, cam.viewport_height, 0);
	u = create_vec3_xyz(0, 0, cam.focal_length);
	cam.lower_left_corner = sub_vec3(cam.origin,
			add_vec3(add_vec3(div_n_vec3(cam.horizontal, 2),
					div_n_vec3(cam.vertical, 2)), u));
	return (cam);
}

t_ray	camera_get_ray(t_cam cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam.origin;
	ray.direction = add_vec3(cam.lower_left_corner,
			add_vec3(mul_n_vec3(cam.horizontal, u),
				mul_n_vec3(sub_vec3(cam.vertical,
						cam.origin), v)));
	return (ray);
}
