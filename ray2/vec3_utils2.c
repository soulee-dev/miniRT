/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:31:30 by soulee            #+#    #+#             */
/*   Updated: 2023/04/27 17:51:54 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	add_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x + v.x;
	vec3.y = u.y + v.y;
	vec3.z = u.z + v.z;
	return (vec3);
}

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

t_vec3	at(t_vec3 origin, t_vec3 dir, double t)
{
	return (add_vec3(origin, mul_n_vec3(dir, t)));
}
