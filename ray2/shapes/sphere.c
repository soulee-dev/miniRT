/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:39:43 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 11:34:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	sphere_hit(t_ray *r, double t_min, double t_max, t_hit_record *rec, t_sphere sphere)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_vec3	outward_normal;

	oc = sub_vec3(r->origin, sphere.center);
	a = length_squared(r->direction);
	half_b = dot(oc, r->direction);
	c = length_squared(oc) - sphere.radius * sphere.radius;
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
	rec->p = at(*r, rec->t);
	outward_normal = div_n_vec3(sub_vec3(rec->p, sphere.center), sphere.radius);
	set_face_normal(rec, r, &outward_normal);
	rec->mat_ptr = sphere.mat_ptr;
	return (1);
}
