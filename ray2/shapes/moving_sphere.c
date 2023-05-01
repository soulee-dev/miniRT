/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:47:52 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 11:05:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_point3	center(t_moving_sphere moving_sphere, double time)
{
	return (
		add_vec3(moving_sphere.center0, \
			mul_n_vec3(sub_vec3(moving_sphere.center0, moving_sphere.center1), \
				((time - moving_sphere.time0) \
					/ (moving_sphere.time1 - moving_sphere.time0))))
	);
}

int	moving_sphere_hit(t_ray *r, double t_min, double t_max, \
	t_hit_record *rec, t_moving_sphere moving_sphere)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_vec3	outward_normal;

	oc = sub_vec3(r->origin, center(moving_sphere, r->time));
	a = length_squared(r->direction);
	half_b = dot(oc, r->direction);
	c = length_squared(oc) - moving_sphere.radius * moving_sphere.radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < t_min || t_max < root)
			return (0);
	}
	rec->t = root;
	rec->p = at(r->origin, r->direction, rec->t);
	outward_normal = div_n_vec3(sub_vec3(rec->p, \
			center(moving_sphere, r->time)), moving_sphere.radius);
	set_face_normal(rec, r, &outward_normal);
	rec->mat_ptr = moving_sphere.mat_ptr;
	return (1);

}