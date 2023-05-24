/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:01:12 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 18:14:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_color	phong_lighting(t_scene *scene)
{
	t_color		light_color;
	t_object	*lights;

	light_color = color(0, 0, 0);
	lights = scene->lights;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = add_vec3(light_color,
					point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = add_vec3(light_color, scene->ambient);
	return (min_vec3(mul_vec3(light_color, scene->rec.albedo), color(1, 1, 1)));
}

t_color	point_light_get(t_scene *scene, t_light *light)
{
	t_color	diffuse;
	t_vec3	light_dir;
	double	kd;
	t_color	specular;
	double	light_len;
	t_ray	light_ray;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;
	double	ksn;
	double	ks;
	double	brightness;

	light_dir = sub_vec3(light->orig, scene->rec.p);
	light_len = length(light_dir);
	light_ray = ray(add_vec3(scene->rec.p, \
		mul_n_vec3(scene->rec.normal, EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color(0, 0, 0));
	light_dir = unit_vector(light_dir);
	kd = fmax(dot(scene->rec.normal, light_dir), 0.0);
	diffuse = mul_n_vec3(light->light_color, kd);
	view_dir = unit_vector(mul_n_vec3(scene->ray.dir, -1));
	reflect_dir = reflect(mul_n_vec3(light_dir, -1), scene->rec.normal);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(dot(view_dir, reflect_dir), 0.0), ksn);
	specular = mul_n_vec3(mul_n_vec3(light->light_color, ks), spec);
	brightness = light->bright_ratio * LUMEN;
	return (mul_n_vec3(add_vec3(add_vec3(scene->ambient, diffuse), \
		specular), brightness));
}

int	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (1);
	return (0);
}
