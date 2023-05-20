/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:57:29 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 14:20:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	return (ray);
}

t_vec3	at(t_ray *r, double t)
{
	return (add_vec3(r->orig, mul_n_vec3(r->dir, t)));
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = unit_vector(sub_vec3(add_vec3(add_vec3(\
		cam->left_bottom, mul_n_vec3(cam->horizontal, u)), \
			mul_n_vec3(cam->vertical, v)), cam->orig));
	return (ray);
}

t_color	ray_color(t_ray *ray, t_sphere *sp)
{
	double	t;
	t_vec3	n;

	t = hit_sphere(sp, ray);
	if (t > 0.0)
	{
		n = unit_vector(sub_vec3(at(ray, t), sp->center));
		return (mul_n_vec3(color(n.x + 1, n.y + 1, n.z + 1), 0.5));
	}

	t = 0.5 * (ray->dir.y + 1.0);
	return (add_vec3(mul_n_vec3(color(1, 1, 1), 1.0 - t), \
		mul_n_vec3(color(0.5, 0.7, 1.0), t)));
}
