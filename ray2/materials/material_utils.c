/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:16:25 by soulee            #+#    #+#             */
/*   Updated: 2023/05/15 19:27:42 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	hit_material(t_ray *r_in, t_hit_record *rec, \
	t_color *attenuation, t_ray *scattered)
{
	int	is_hit;

	is_hit = 0;
	if (rec->mat_ptr.type == MATERIAL_LAMBERTIAN)
			is_hit = lambertian_scatter(r_in, rec, \
				attenuation, scattered, rec->mat_ptr.lambertian);
	else if (rec->mat_ptr.type == MATERIAL_METAL)
		is_hit = metal_scatter(r_in, rec, \
			attenuation, scattered, rec->mat_ptr.metal);
	else if (rec->mat_ptr.type == MATERIAL_DIELECTRIC)
		is_hit = dielectric_scatter(r_in, rec, \
			attenuation, scattered, rec->mat_ptr.dielectric);
	return (is_hit);
}

t_color	material_emitted(t_material material, double u, double v, t_point3 *p)
{
	(void) u;
	(void) v;
	(void) p;
	if (material.type == MATERIAL_DIFFUSE_LIGHT)
		return (diffuse_light_emitted(material.diffuse_light.emit));
	else
		return (create_vec3_t(0.0));
}
