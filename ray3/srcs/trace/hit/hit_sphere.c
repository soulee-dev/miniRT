/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:03:00 by soulee            #+#    #+#             */
/*   Updated: 2023/05/21 15:46:15 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

int	hit_sphere(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;

	sp = obj->element;
	oc = sub_vec3(ray->orig, sp->center);
	a = length_squared(ray->dir);
	half_b = dot(oc, ray->dir);
	c = length_squared(oc) - sp->radius * sp->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (0);
	}
	rec->t = root;
	rec->p = at(ray, root);
	rec->normal = div_n_vec3(sub_vec3(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (1);
}
