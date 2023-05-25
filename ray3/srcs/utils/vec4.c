/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:54:56 by soulee            #+#    #+#             */
/*   Updated: 2023/05/25 21:45:23 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

t_vec3	min_vec3(t_vec3 u, t_vec3 v)
{
	if (u.x > v.x)
		u.x = v.x;
	if (u.y > v.y)
		u.y = v.y;
	if (u.z > v.z)
		u.z = v.z;
	return (u);
}

t_vec3	sub_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x - v.x;
	vec3.y = u.y - v.y;
	vec3.z = u.z - v.z;
	return (vec3);
}
