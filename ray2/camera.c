/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:11:17 by soulee            #+#    #+#             */
/*   Updated: 2023/05/08 14:14:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	init_camera(t_point3 lookfrom, t_point3 lookat, t_vec3 vup,
		double vfov, double aspect_ratio, double aperture, double focus_dist, double _time0, double _time1)
{
	t_cam	cam;
	double	theta;
	double	h;
	double	viewport_height;
	double	viewport_width;

	theta = degrees_to_radians(vfov);
	h = tan(theta / 2);
	viewport_height = 2.0 * h;
	viewport_width = aspect_ratio * viewport_height;
	cam.w = unit_vector(sub_vec3(lookfrom, lookat));
	cam.u = unit_vector(cross(vup, cam.w));
	cam.v = cross(cam.w, cam.u);
	cam.origin = lookfrom;
	cam.horizontal = mul_n_vec3(cam.u, focus_dist * viewport_width);
	cam.vertical = mul_n_vec3(cam.v, focus_dist * viewport_height);
	cam.lower_left_corner = sub_vec3(cam.origin,
			add_vec3(add_vec3(div_n_vec3(cam.horizontal, 2),
					div_n_vec3(cam.vertical, 2)),
				mul_n_vec3(cam.w, focus_dist)));
	cam.lense_radius = aperture / 2.0;
	cam.time0 = _time0;
	cam.time1 = _time1;
	return (cam);
}

t_ray	camera_get_ray(t_cam cam, double s, double t)
{
	t_vec3	rd;
	t_vec3	offset;
	t_ray	ray;

	rd = mul_n_vec3(random_in_unit_disk(), cam.lense_radius);
	offset = add_vec3(mul_n_vec3(cam.u, rd.x), mul_n_vec3(cam.v, rd.y));
	ray.origin = add_vec3(cam.origin, offset);
	ray.direction = sub_vec3(sub_vec3(add_vec3(cam.lower_left_corner,
					add_vec3(mul_n_vec3(cam.horizontal, s),
						mul_n_vec3(cam.vertical, t))), cam.origin), offset);
	ray.time = random_double2(cam.time0, cam.time1);
	return (ray);
}
