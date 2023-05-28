/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:31:28 by soulee            #+#    #+#             */
/*   Updated: 2023/05/28 17:38:50 by soulee           ###   ########.fr       */
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

t_color	color(double r, double g, double b)
{
	t_color	color;

	color.x = r;
	color.y = g;
	color.z = b;
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

t_vec3	print_vec3(t_vec3 vec)
{
	printf("x: %lf, y: %lf, z:%lf\n", vec.x, vec.y, vec.z);
}
