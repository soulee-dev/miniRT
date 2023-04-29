/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:54:45 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 20:26:02 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	metal_scatter(t_ray *r_in, t_hit_record *rec,
		t_color *attenuation, t_ray *scattered, t_color albedo)
{
	t_ray	ray;
	t_vec3	reflected;

	reflected = reflect(unit_vector(r_in->direction), rec->normal);
	ray.origin = rec->p;
	ray.direction = reflected;
	*scattered = ray;
	*attenuation = albedo;
	return (dot(scattered->direction, rec->normal) > 0.0);
}
