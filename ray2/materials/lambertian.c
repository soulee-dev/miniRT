/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:47:06 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 19:51:49 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	lambertian_scatter(t_ray *r_in, t_hit_record *rec,
		t_color *attenuation, t_ray *scattered, t_color albedo)
{
	t_ray	ray;
	t_vec3	scatter_direction;

	scatter_direction = add_vec3(rec->normal, random_in_unit_sphere());
	if (near_zero(scatter_direction))
		scatter_direction = rec->normal;
	ray.origin = rec->p;
	ray.direction = scatter_direction;
	*scattered = ray;
	*attenuation = albedo;
	return (1);
}
