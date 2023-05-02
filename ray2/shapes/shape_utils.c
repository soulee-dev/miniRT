/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:48:52 by soulee            #+#    #+#             */
/*   Updated: 2023/05/02 18:58:32 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	hit(t_shape shape, t_ray *r, double t_min, \
	double t_max, t_hit_record *rec)
{
	int	is_hit;

	is_hit = 0;
	if (shape.type == SHAPE_SPHERE)
		is_hit = sphere_hit(shape.sphere, r, t_min, t_max, rec);
	else if (shape.type == SHAPE_MOVING_SPHERE)
		is_hit = moving_sphere_hit(shape.moving_sphere, r, t_min, t_max, rec);
	return (is_hit);
}

int	bounding_box(t_shape shape, t_ray *r, double time0, \
	double time1, t_aabb *output_box)
{
	int	is_bounding_box;

	is_bounding_box = 0;
	if (shape.type == SHAPE_SPHERE)
		is_bounding_box = sphere_bounding_box(shape.sphere, \
			time0, time1, output_box);
	else if (shape.type == SHAPE_MOVING_SPHERE)
		is_bounding_box = moving_sphere_bounding_box(shape.moving_sphere, \
			time0, time1, output_box);
	return (is_bounding_box);
}
