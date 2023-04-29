/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:45:03 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 22:49:47 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	dielectric_scatter(t_ray *r_in, t_hit_record *rec,
		t_color *attenuation, t_ray *scattered, t_material material)
{
	double	refraction_ratio;
	t_vec3	unit_direction;
	t_vec3	refracted;
	t_ray	ray;

	*attenuation = create_vec3_t(1.0);
	if (rec->front_face)
		refraction_ratio = (1.0 / material.ir);
	else
		refraction_ratio = material.ir;
	unit_direction = unit_vector(r_in->direction);
	refracted = refract(unit_direction, rec->normal, refraction_ratio);
	ray.origin = rec->p;
	ray.direction = refracted;
	*scattered = ray;
	return (1);
}
