/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:38:25 by soulee            #+#    #+#             */
/*   Updated: 2023/05/02 20:05:50 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	aabb_hit(t_aabb aabb, t_ray *r, double t_min, double t_max)
{
	int		i;
	double	t0;
	double	t1;

	i = 0;
	while (i < 3)
	{
		t0 = fmin((nth_vec3(aabb.minimum, i) - nth_vec3(r->origin, i)) / nth_vec3(r->direction, i),
				(nth_vec3(aabb.maximum, i) - nth_vec3(r->origin, i)) / nth_vec3(r->direction, i));
		t1 = fmax((nth_vec3(aabb.minimum, i) - nth_vec3(r->origin, i)) / nth_vec3(r->direction, i),
				(nth_vec3(aabb.maximum, i) - nth_vec3(r->origin, i)) / nth_vec3(r->direction, i));
		t_min = fmax(t0, t_min);
		t_max = fmin(t1, t_max);
		if (t_max <= t_min)
			return (0);
		i++;
	}
	return (1);
}

t_aabb	surrounding_box(t_aabb box0, t_aabb box1)
{
	t_aabb		aabb;
	t_point3	small;
	t_point3	big;

	small = create_vec3_xyz(\
		(fmin(box0.minimum.x, box1.minimum.x)), \
		(fmin(box0.minimum.y, box1.minimum.y)), \
		(fmin(box0.minimum.z, box1.minimum.z)));
	big = create_vec3_xyz(\
		(fmax(box0.maximum.x, box1.maximum.x)), \
		(fmax(box0.maximum.y, box1.maximum.y)), \
		(fmax(box0.maximum.z, box1.maximum.z)));
	aabb.minimum = small;
	aabb.maximum = big;
	return (aabb);
}
