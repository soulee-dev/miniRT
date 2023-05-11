/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:47:06 by soulee            #+#    #+#             */
/*   Updated: 2023/05/11 17:32:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	lambertian_scatter(t_ray *r_in, t_hit_record *rec,
		t_color *attenuation, t_ray *scattered, t_lambertian lambertian)
{
	t_ray	ray;
	t_vec3	scatter_direction;

	(void) r_in;
	scatter_direction = add_vec3(rec->normal, random_in_unit_sphere());
	if (near_zero(scatter_direction))
		scatter_direction = rec->normal;
	ray.origin = rec->p;
	ray.direction = scatter_direction;
	ray.time = r_in->time;
	*scattered = ray;
	*attenuation = value(lambertian.albedo, rec->u, rec->v, &rec->p);
	return (1);
}
