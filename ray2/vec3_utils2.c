/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:31:30 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 16:58:51 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	div_n_vec3(t_vec3 u, double t)
{
	t_vec3	vec3;

	vec3.x = u.x / t;
	vec3.y = u.y / t;
	vec3.z = u.z / t;
	return (vec3);
}

t_vec3	unit_vector(t_vec3 u)
{
	return (div_n_vec3(u, length(u)));
}

t_vec3	at(t_vec3 origin, t_vec3 direction, double t)
{
	return (add_vec3(origin, mul_n_vec3(direction, t)));
}

t_vec3	create_vec3_t(double t)
{
	t_vec3	vec3;

	vec3.x = t;
	vec3.y = t;
	vec3.z = t;
	return (vec3);
}

t_vec3	create_vec3_xyz(double x, double y, double z)
{
	t_vec3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}
