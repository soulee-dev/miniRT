/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:29:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 20:31:41 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

void	set_parameters(t_object *obj, t_discriminant *disc, t_ray *ray)
{
	t_cylinder		*cy;

	cy = obj->element;
	disc->u = ray->dir;
	disc->o = cy->dir;
	disc->delta_p = sub_vec3(ray->orig, cy->center);
	disc->a = length_squared(cross(disc->u, disc->o));
	disc->half_b = dot(cross(disc->u, disc->o), cross(disc->delta_p, disc->o));
	disc->c = length_squared(cross(disc->delta_p, disc->o)) - \
		pow(cy->diameter / 2, 2);
	disc->discriminant = disc->half_b * disc->half_b - disc->a * disc->c;
}
