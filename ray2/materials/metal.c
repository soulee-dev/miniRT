/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:54:45 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 11:09:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	metal_scatter(t_ray *r_in, t_hit_record *rec,
		t_color *attenuatiton, t_ray *scattered, t_material material)
{
	t_vec3	reflected;
	t_ray	ray;

	if (material.fuzz >= 1.0)
		material.fuzz = 1.0;
	reflected = reflect(unit_vector(r_in->direction), rec->normal);
	ray.origin = rec->p;
	ray.direction = add_vec3(reflected,
			mul_n_vec3(random_in_unit_sphere(), material.fuzz));
	ray.time = r_in->time;
	*scattered = ray;
	*attenuatiton = material.albedo;
	return (dot(scattered->direction, rec->normal) > 0);
}
