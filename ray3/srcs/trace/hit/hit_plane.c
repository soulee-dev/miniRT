/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:20:43 by soulee            #+#    #+#             */
/*   Updated: 2023/05/23 21:29:11 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

int	hit_plane(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	double	numrator;
	double	denominator;
	double	root;

	pl = obj->element;
	denominator = dot(ray->dir, pl->normal);
	if (denominator < EPSILON)
		return (0);
	numrator = dot(sub_vec3(pl->point, ray->orig), pl->normal);
	root = numrator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = at(ray, root);
	rec->albedo = obj->albedo;
	return (1);
}
