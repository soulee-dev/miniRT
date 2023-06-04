/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:03:00 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 20:19:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

int	hit_sphere(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_discriminant	disc;
	t_sphere		*sp;

	sp = obj->element;
	disc.oc = sub_vec3(ray->orig, sp->center);
	disc.a = length_squared(ray->dir);
	disc.half_b = dot(disc.oc, ray->dir);
	disc.c = length_squared(disc.oc) - sp->radius * sp->radius;
	disc.discriminant = disc.half_b * disc.half_b - disc.a * disc.c;
	if (disc.discriminant < 0)
		return (0);
	disc.sqrtd = sqrt(disc.discriminant);
	disc.root = (-disc.half_b - disc.sqrtd) / disc.a;
	if (disc.root < rec->tmin || rec->tmax < disc.root)
	{
		disc.root = (-disc.half_b + disc.sqrtd) / disc.a;
		if (disc.root < rec->tmin || rec->tmax < disc.root)
			return (0);
	}
	rec->t = disc.root;
	rec->p = at(ray, disc.root);
	rec->normal = div_n_vec3(sub_vec3(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (1);
}
