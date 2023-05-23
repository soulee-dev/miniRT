/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:59:53 by soulee            #+#    #+#             */
/*   Updated: 2023/05/23 21:26:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

t_object	*object(int type, void *element, t_color albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	// Exit error when malloc failed;
	if (!new)
		;
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
		;
	// Exit error when malloc failed;
	light->orig = orig;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	// Exit error when malloc failed;
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		;
	sp->center = center;
	sp->radius = radius;
	return (sp);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 dir,
	double diameter, double height)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	// Exit error when malloc failed;
	if (!cy)
		;
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
	// Exit error when malloc faield;
	if (!pl)
		;
	pl->point = point;
	pl->normal = normal;
	return (pl);
}
