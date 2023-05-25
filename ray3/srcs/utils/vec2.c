/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:31:30 by soulee            #+#    #+#             */
/*   Updated: 2023/05/25 21:51:50 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

t_vec3	add_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x + v.x;
	vec3.y = u.y + v.y;
	vec3.z = u.z + v.z;
	return (vec3);
}

t_vec3	sub_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x - v.x;
	vec3.y = u.y - v.y;
	vec3.z = u.z - v.z;
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

t_vec3	mul_n_vec3(t_vec3 u, double t)
{
	t_vec3	vec3;

	vec3.x = u.x * t;
	vec3.y = u.y * t;
	vec3.z = u.z * t;
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
