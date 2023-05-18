/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:39:43 by soulee            #+#    #+#             */
/*   Updated: 2023/05/18 15:18:33 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	sphere_hit(t_sphere sphere, t_ray *r, double t_min, double t_max, t_hit_record *rec)
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
	sphere_get_uv(&outward_normal, &rec->u, &rec->v);
	rec->mat_ptr = sphere.mat_ptr;
	return (1);
}

int	sphere_bounding_box(t_sphere sphere, double time0, \
	double time1, t_aabb *output_box)
{
	(void)time0;
	(void)time1;
	output_box->minimum = sub_vec3(sphere.center, create_vec3_t(sphere.radius));
	output_box->maximum = add_vec3(sphere.center, create_vec3_t(sphere.radius));
	return (1);
}

void	sphere_get_uv(t_point3 *p, double *u, double *v)
{
	double	theta;
	double	phi;

	theta = acos(-p->y);
	phi = atan2(-p->z, p->x + M_PI);
	*u = phi / (2 * M_PI);
	*v = theta / M_PI;
}
