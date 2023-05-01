/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:37:40 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 11:32:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_hit_record *rec, \
	t_ray *r, t_vec3 *outward_normal)
{
	int	front_face;

	front_face = dot(r->direction, *outward_normal) < 0;
	if (front_face)
		rec->normal = *outward_normal;
	else
		rec->normal = mul_n_vec3(*outward_normal, -1);
}
