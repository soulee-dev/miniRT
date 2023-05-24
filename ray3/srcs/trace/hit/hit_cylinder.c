/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:52:19 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:55 by soulee           ###   ########.fr       */
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
	double		r;
	t_vec3		circle_center;
	double		root;
	double		diameter;

	cy = obj->element;
	r = cy->diameter / 2;
	circle_center = add_vec3(cy->center, mul_n_vec3(cy->dir, height));
	root = dot(sub_vec3(circle_center, ray->orig), cy->dir) / dot(ray->dir, cy->dir);
	diameter = length(sub_vec3(circle_center, at(ray, root)));
	if (fabs(r) < fabs(diameter))
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
	t_cylinder	*cy;
	double		a;
	double		half_b;
	double		c;
	t_vec3		u;
	t_vec3		o;
	t_vec3		delta_P;
	double		r;
	double		discriminant;
	double		sqrtd;
	double		root;
	double		hit_height;

	cy = obj->element;
	u = ray->dir;
	o = cy->dir;
	r = cy->diameter / 2;
	delta_P = sub_vec3(ray->orig, cy->center);
	a = length_squared(cross(u, o));
	half_b = dot(cross(u, o), cross(delta_P, o));
	c = length_squared(cross(delta_P, o)) - pow(r, 2);
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
	if (!cy_boundary(cy, at(ray, root), &hit_height))
		return (0);
	rec->t = root;
	rec->p = at(ray, root);
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
