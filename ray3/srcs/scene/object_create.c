/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:59:53 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 16:36:26 by soulee           ###   ########.fr       */
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
