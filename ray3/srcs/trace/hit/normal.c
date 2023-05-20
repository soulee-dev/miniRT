/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:34:35 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 14:36:13 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = dot(r->dir, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = mul_n_vec3(rec->normal, -1);
}
