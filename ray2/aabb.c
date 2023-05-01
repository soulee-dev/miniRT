/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:38:25 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 12:50:59 by soulee           ###   ########.fr       */
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
