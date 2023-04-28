/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:37:40 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 18:47:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_hit_record *hit_record,
	t_ray *r, t_vec3 *outward_normal)
{
	int	front_face;

	front_face = dot(r->direction, *outward_normal) < 0;
	if (front_face)
		hit_record->normal = *outward_normal;
	else
		hit_record->normal = mul_n_vec3(*outward_normal, -1);
}
