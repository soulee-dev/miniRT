/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:16:25 by soulee            #+#    #+#             */
/*   Updated: 2023/05/03 20:28:38 by soulee           ###   ########.fr       */
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
