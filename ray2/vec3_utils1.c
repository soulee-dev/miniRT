/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:31:28 by soulee            #+#    #+#             */
/*   Updated: 2023/04/27 17:41:01 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	create_vec3(double t)
{
	t_vec3	vec3;

	vec3.x = t;
	vec3.y = t;
	vec3.z = t;
	return (vec3);
}

t_vec3	mul_n_vec3(t_vec3 u, double t)
{
	t_vec3	vec3;

	vec3.x = u.x * t;
	vec3.y = u.y * t;
	vec3.z = u.z * t;
	return (vec3);
}

t_vec3	mul_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x * v.x;
	vec3.y = u.y * v.y;
	vec3.z = u.z * v.z;
	return (vec3);
}

double	dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	sub_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x - v.x;
	vec3.y = u.y - v.y;
	vec3.z = u.z - v.z;
	return (vec3);
}
