/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:52:19 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 20:23:42 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

int	cy_boundary(t_cylinder *cy, t_vec3 at_point, double *hit_height)
{
	double	max_height;

	*hit_height = dot(sub_vec3(at_point, cy->center), cy->dir);
	max_height = cy->height / 2;
	if (fabs(*hit_height) > max_height)
		return (0);
	return (1);
}

t_vec3	get_cylinder_normal(t_cylinder *cy, t_vec3 at_point, double hit_height)
{
	t_point3	hit_center;
	t_vec3		normal;

	hit_center = add_vec3(cy->center, mul_n_vec3(cy->dir, hit_height));
	normal = sub_vec3(at_point, hit_center);
	return (unit_vector(normal));
}

int	hit_cylinder_cap(t_object *obj, t_ray *ray, \
	t_hit_record *rec, double height)
{
	t_cylinder	*cy;
	t_vec3		circle_center;
	double		root;
	double		diameter;

	cy = obj->element;
	circle_center = add_vec3(cy->center, mul_n_vec3(cy->dir, height));
	root = dot(sub_vec3(circle_center, ray->orig), \
		cy->dir) / dot(ray->dir, cy->dir);
	diameter = length(sub_vec3(circle_center, at(ray, root)));
	if (fabs(cy->diameter / 2) < fabs(diameter))
		return (0);
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = at(ray, root);
	rec->tmax = rec->t;
	if (0 < height)
		rec->normal = cy->dir;
	else
		rec->normal = mul_n_vec3(cy->dir, -1);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (1);
}

int	hit_cylinder_side(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_discriminant	disc;
	t_cylinder		*cy;
	double			hit_height;

	cy = obj->element;
	disc.u = ray->dir;
	disc.o = cy->dir;
	disc.delta_p = sub_vec3(ray->orig, cy->center);
	disc.a = length_squared(cross(disc.u, disc.o));
	disc.half_b = dot(cross(disc.u, disc.o), cross(disc.delta_p, disc.o));
	disc.c = length_squared(cross(disc.delta_p, disc.o)) - pow(cy->diameter / 2, 2);
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
	if (!cy_boundary(cy, at(ray, disc.root), &hit_height))
		return (0);
	rec->t = disc.root;
	rec->p = at(ray, disc.root);
	rec->normal = get_cylinder_normal(cy, rec->p, hit_height);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (1);
}

int	hit_cylinder(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	int			result;
	t_cylinder	*cy;

	cy = obj->element;
	result = 0;
	result += hit_cylinder_cap(obj, ray, rec, cy->height / 2);
	result += hit_cylinder_cap(obj, ray, rec, -(cy->height / 2));
	result += hit_cylinder_side(obj, ray, rec);
	return (result);
}
