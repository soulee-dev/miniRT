/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:44:24 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 16:25:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int				hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = 0;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = 1;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

int	hit_obj(t_object *objs, t_ray *ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = 0;
	if (objs->type == SPHERE)
		hit_result = hit_sphere(objs, ray, rec);
	return (hit_result);
}
