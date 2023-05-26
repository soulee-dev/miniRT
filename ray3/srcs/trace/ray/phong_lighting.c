/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:01:12 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 20:07:41 by soulee           ###   ########.fr       */
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
	t_phong_light	phong_light;

	phong_light.light_dir = sub_vec3(light->orig, scene->rec.p);
	phong_light.light_len = length(phong_light.light_dir);
	phong_light.light_ray = ray(add_vec3(scene->rec.p, \
		mul_n_vec3(scene->rec.normal, EPSILON)), phong_light.light_dir);
	if (in_shadow(scene->world, phong_light.light_ray, phong_light.light_len))
		return (color(0, 0, 0));
	phong_light.light_dir = unit_vector(phong_light.light_dir);
	phong_light.kd = fmax(dot(scene->rec.normal, phong_light.light_dir), 0.0);
	phong_light.diffuse = mul_n_vec3(light->light_color, phong_light.kd);
	phong_light.view_dir = unit_vector(mul_n_vec3(scene->ray.dir, -1));
	phong_light.reflect_dir = reflect(\
		mul_n_vec3(phong_light.light_dir, -1), scene->rec.normal);
	phong_light.ksn = 64;
	phong_light.ks = 0.5;
	phong_light.spec = pow(fmax(dot(phong_light.view_dir, \
		phong_light.reflect_dir), 0.0), phong_light.ksn);
	phong_light.specular = mul_n_vec3(mul_n_vec3(light->light_color, \
		phong_light.ks), phong_light.spec);
	phong_light.brightness = light->bright_ratio * LUMEN;
	return (mul_n_vec3(add_vec3(add_vec3(scene->ambient, phong_light.diffuse), \
		phong_light.specular), phong_light.brightness));
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
