/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:11:17 by soulee            #+#    #+#             */
/*   Updated: 2023/04/30 00:15:21 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	init_camera(t_point3 lookfrom, t_point3 lookat, t_vec3 vup,
		double vfov, double aspect_ratio)
{
	t_cam	cam;
	double	theta;
	double	h;
	double	viewport_height;
	double	viewport_width;
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	theta = degrees_to_radians(vfov);
	h = tan(theta / 2);
	viewport_height = 2.0 * h;
	viewport_width = aspect_ratio * viewport_height;
	w = unit_vector(sub_vec3(lookfrom, lookat));
	u = unit_vector(cross(vup, w));
	v = cross(w, u);
	cam.origin = lookfrom;
	cam.horizontal = mul_n_vec3(u, viewport_width);
	cam.vertical = mul_n_vec3(v, viewport_height);
	cam.lower_left_corner = sub_vec3(cam.origin,
			add_vec3(add_vec3(div_n_vec3(cam.horizontal, 2),
					div_n_vec3(cam.vertical, 2)), w));
	return (cam);
}

t_ray	camera_get_ray(t_cam cam, double s, double t)
{
	t_ray	ray;

	ray.origin = cam.origin;
	ray.direction = sub_vec3(add_vec3(cam.lower_left_corner,
				add_vec3(mul_n_vec3(cam.horizontal, s),
					mul_n_vec3(cam.vertical, t))), cam.origin);
	return (ray);
}
