/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:11:02 by soulee            #+#    #+#             */
/*   Updated: 2023/05/07 14:36:25 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	cylinder_boundary(t_cylinder cylinder, t_vec3 at_point, double *hit_height)
{
	double	max_height;

	*hit_height = dot(sub_vec3(at_point, cylinder.center), \
		cylinder.direction);
	max_height = cylinder.height / 2;
	if (fabs(*hit_height) > max_height)
		return (0);
	return (1);
}

t_vec3	cylinder_normal(t_cylinder cylinder, \
	t_vec3 at_point, double hit_height)
{
	t_point3	hit_center;
	t_vec3		normal;

	hit_center = add_vec3(cylinder.center, \
		mul_n_vec3(cylinder.direction, hit_height));
	normal = sub_vec3(at_point, hit_center);
	return (unit_vector(normal));
}

int	hit_cylinder_cap(t_cylinder cylinder, \
	t_ray *ray, double t_min, double t_max, t_hit_record *rec, double height)
{
	double	r;
	t_vec3	circle_center;
	float	root;
	float	diameter;
	t_vec3	outward_normal;

	r = cylinder.diameter / 2;
	circle_center = add_vec3(cylinder.center, mul_n_vec3(cylinder.direction, height));
	root = dot(sub_vec3(circle_center, ray->origin), cylinder.direction) / dot(ray->direction, cylinder.direction);
	diameter = length(sub_vec3(circle_center, at(*ray, root)));
	if (fabs(r) < fabs(diameter))
		return (0);
	if (root < t_min || t_max < root)
		return (0);
	rec->t = root;
	rec->p = at(*ray, rec->t);
	if (0 < height)
		outward_normal = cylinder.direction;
	else
		outward_normal = mul_n_vec3(cylinder.direction, -1);
	set_face_normal(rec, ray, &outward_normal);
	rec->mat_ptr = cylinder.mat_ptr;
	return (1);
}

int	hit_cylinder_side(t_cylinder cylinder, t_ray *ray, double t_min, \
	double t_max, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	c;
	t_vec3	u;
	t_vec3	o;
	t_vec3	delta_P;
	double	radius;
	double	discriminant;
	double	sqrtd;
	double	root;
	double	hit_height;	
	t_vec3	outward_normal;

	u = ray->direction;
	o = cylinder.direction;
	radius = cylinder.diameter / 2;
	delta_P = sub_vec3(ray->origin, cylinder.center);
	a = length_squared(cross(u, o));
	half_b = dot(cross(u, o), cross(delta_P, o));
	c = length_squared(cross(delta_P, o)) - radius * radius;
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
	if (!cylinder_boundary(cylinder, at(*ray, root), &hit_height))
		return (0);
	rec->t = root;
	rec->p = at(*ray, rec->t);
	outward_normal = cylinder_normal(cylinder, rec->p, hit_height);
	set_face_normal(rec, ray, &outward_normal);
	rec->mat_ptr = cylinder.mat_ptr;
	return (1);
}

int	cylinder_hit(t_cylinder cylinder, t_ray *ray, double t_min, \
	double t_max, t_hit_record *rec)
{
	int	result;

	result = 0;
	result += hit_cylinder_cap(cylinder, ray, t_min, t_max, \
		rec, cylinder.height / 2);
	result += hit_cylinder_cap(cylinder, ray, t_min, t_max, \
		rec, -(cylinder.height / 2));
	result += hit_cylinder_side(cylinder, ray, t_min, t_max, rec);
	return (result);
}
