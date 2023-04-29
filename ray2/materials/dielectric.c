/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:45:03 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 23:13:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	dielectric_scatter(t_ray *r_in, t_hit_record *rec,
		t_color *attenuation, t_ray *scattered, t_material material)
{
	double	refraction_ratio;
	t_vec3	unit_direction;
	double	cos_theta;
	double	sin_theta;
	int		cannot_refract;
	t_vec3	direction;
	t_ray	ray;

	*attenuation = create_vec3_t(1.0);
	if (rec->front_face)
		refraction_ratio = (1.0 / material.ir);
	else
		refraction_ratio = material.ir;
	unit_direction = unit_vector(r_in->direction);
	cos_theta = fmin(dot(mul_n_vec3(unit_direction, -1), rec->normal), 1.0);
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	cannot_refract = refraction_ratio * sin_theta > 1.0;
	if (cannot_refract)
		direction = reflect(unit_direction, rec->normal);
	else
		direction = refract(unit_direction, rec->normal, refraction_ratio);
	ray.origin = rec->p;
	ray.direction = direction;
	*scattered = ray;
	return (1);
}
