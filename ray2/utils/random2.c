/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:40:40 by soulee            #+#    #+#             */
/*   Updated: 2023/05/02 20:04:56 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	random_unit_vector(void)
{
	return (unit_vector(random_in_unit_sphere()));
}

t_vec3	random_in_hemisphere(t_vec3 normal)
{
	t_vec3	in_unit_sphere;

	in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	else
		return (mul_n_vec3(in_unit_sphere, -1));
}

int	random_int(int min, int max)
{
	return ((int)(random_double2(min, max + 1)));
}
