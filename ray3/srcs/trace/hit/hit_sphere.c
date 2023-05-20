/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:03:00 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 14:15:57 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = sub_vec3(ray->orig, sp->center);
	a = dot(ray->dir, ray->dir);
	b = 2.0 * dot(oc, ray->dir);
	c = dot(oc, oc) - sp->radius * sp->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}
