/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:35:42 by soulee            #+#    #+#             */
/*   Updated: 2023/05/02 19:27:20 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	bvh_node_hit(t_bvh_node bvh_node, t_ray *r, double t_min, \
	double t_max, t_hit_record *rec)
{
	int	hit_left;
	int	hit_right;
	int	temp_max;

	if (!aabb_hit(bvh_node.box, r, t_min, t_max))
		return (0);
	hit_left = hit(bvh_node.left, r, t_min, t_max, rec);
	if (hit_left)
		temp_max = rec->t;
	else
		temp_max = t_max;
	hit_right = hit(bvh_node.right, r, t_min, temp_max, rec);
	return (hit_left || hit_right);
}
