/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:54:45 by soulee            #+#    #+#             */
/*   Updated: 2023/05/03 20:12:05 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	metal_scatter(t_ray *r_in, t_hit_record *rec,
		t_color *attenuatiton, t_ray *scattered, t_metal metal)
{
	t_vec3	reflected;
	t_ray	ray;

	if (metal.fuzz >= 1.0)
		metal.fuzz = 1.0;
	reflected = reflect(unit_vector(r_in->direction), rec->normal);
	ray.origin = rec->p;
	ray.direction = add_vec3(reflected,
			mul_n_vec3(random_in_unit_sphere(), metal.fuzz));
	ray.time = r_in->time;
	*scattered = ray;
	*attenuatiton = metal.albedo;
	return (dot(scattered->direction, rec->normal) > 0);
}
