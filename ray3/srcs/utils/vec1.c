/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:31:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 13:48:53 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_color	color(double x, double y, double z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	point3;

	point3.x = x;
	point3.y = y;
	point3.z = z;
	return (point3);
}

t_vec3	add_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x + v.x;
	vec3.y = u.y + v.y;
	vec3.z = u.z + v.z;
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
