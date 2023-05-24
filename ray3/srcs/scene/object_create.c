/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:59:53 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 18:13:37 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

t_object	*object(int type, void *element, t_color albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		exit_error("error: malloc failed (object)");
	new->type = type;
	new->element = element;
	new->albedo = albedo;
	new->next = NULL;
	return (new);
}

t_light	*light_point(t_point3 orig, t_color light_color, double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		exit_error("error: malloc failed (light_point)");
	light->orig = orig;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		exit_error("error: malloc failed (sphere)");
	sp->center = center;
	sp->radius = radius;
	return (sp);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 dir,
	double diameter, double height)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		exit_error("error: malloc failed (cylinder)");
	cy->center = center;
	cy->dir = dir;
	cy->diameter = diameter;
	cy->height = height;
	return (cy);
}

t_plane	*plane(t_point3 point, t_vec3 normal)
{
	t_plane	*pl;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		exit_error("error: malloc failed (plane)");
	pl->point = point;
	pl->normal = normal;
	return (pl);
}
