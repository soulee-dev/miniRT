/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:06:42 by soulee            #+#    #+#             */
/*   Updated: 2023/05/03 19:20:56 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	box_compare(t_shape a, t_shape b, int axis)
{
	t_aabb	box_a;
	t_aabb	box_b;

	if (!bounding_box(a, 0, 0, &box_a) || !bounding_box(b, 0, 0, &box_b))
		printf("No bounding box in bvh_node constructor.\n");
	return (nth_vec3(box_a.minimum, axis) < nth_vec3(box_b.minimum, axis));
}

int	box_x_compare(t_shape a, t_shape b)
{
	return (box_compare(a, b, 0));
}

int	box_y_compare(t_shape a, t_shape b)
{
	return (box_compare(a, b, 1));
}

int	box_z_compare(t_shape a, t_shape b)
{
	return (box_compare(a, b, 2));
}
