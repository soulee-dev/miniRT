/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:57:29 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 19:16:24 by soulee           ###   ########.fr       */
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

t_hit_record	record_init(void)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	return (rec);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = sub_vec3(add_vec3(cam->lower_left_corner,
				add_vec3(mul_n_vec3(cam->horizontal, u),
					mul_n_vec3(cam->vertical, v))), cam->orig);
	return (ray);
}

t_color	ray_color(t_scene *scene)
{
	double	t;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
	{
		t = 0.5 * (scene->ray.dir.y + 1.0);
		return (add_vec3(mul_n_vec3(\
			color(1, 1, 1), 1.0 - t), \
				mul_n_vec3(color(0.5, 0.7, 1.0), t)));
	}
}
