/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:20:43 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 20:15:22 by soulee           ###   ########.fr       */
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
	denominator = dot(ray->dir, pl->dir);
	if (denominator < EPSILON)
		return (0);
	numrator = dot(sub_vec3(pl->center, ray->orig), pl->dir);
	root = numrator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = at(ray, root);
	rec->normal = pl->dir;
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (1);
}
