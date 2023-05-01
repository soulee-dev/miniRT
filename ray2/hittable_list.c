/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:01:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 11:12:37 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hittable_list_hit(t_hittable_list world, t_ray *r,
		double t_min, double t_max, t_hit_record *rec)
{
	size_t			i;
	t_hit_record	temp_rec;
	int				hit_anything;
	double			closest_so_far;
	double			is_hit;

	hit_anything = 0;
	closest_so_far = t_max;
	i = 0;
	while (i < world.size)
	{
		is_hit = 0;
		if (world.objects[i].type == SHAPE_SPHERE)
			is_hit = sphere_hit(r, t_min, closest_so_far, \
				&temp_rec, world.objects[i].sphere);
		if (world.objects[i].type == SHAPE_MOVING_SPHERE)
			is_hit = moving_sphere_hit(r, t_min, closest_so_far, \
				&temp_rec, world.objects[i].moving_sphere);
		if (is_hit)
		{
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}
