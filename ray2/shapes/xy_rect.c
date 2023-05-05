/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_rect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:31:18 by soulee            #+#    #+#             */
/*   Updated: 2023/05/05 13:41:31 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	xy_rect_hit(t_xy_rect xy_rect, t_ray *r, double t_min, \
	double t_max, t_hit_record *rec)
{
	double	t;
	double	x;
	double	y;
	t_vec3	outward_normal;

	t = (xy_rect.k - r->origin.z) / r->direction.z;
	if (t < t_min || t > t_max)
		return (0);
	x = r->origin.x + t * r->direction.x;
	y = r->origin.y + t * r->direction.y;
	if (x < xy_rect.x0 || x > xy_rect.x1 || y < xy_rect.y0 || y > xy_rect.y1)
		return (0);
	rec->u = (x - xy_rect.x0) / (xy_rect.x1 - xy_rect.x0);
	rec->v = (y - xy_rect.y0) / (xy_rect.y1 - xy_rect.y0);
	rec->t = t;
	outward_normal = create_vec3_xyz(0, 0, 1);
	set_face_normal(rec, r, &outward_normal);
	rec->mat_ptr = xy_rect.mat_ptr;
	rec->p = at(*r, t);
	return (1);
}
