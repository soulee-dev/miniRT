/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:46:45 by soulee            #+#    #+#             */
/*   Updated: 2023/05/25 21:47:00 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

void	print_vec3(t_vec3 vec3)
{
	printf("x:%lf y:%lf z:%lf\n", vec3.x, vec3.y, vec3.z);
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (sub_vec3(v, mul_n_vec3(n, 2.0 * dot(v, n))));
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	return (
		vec3(
			u.y * v.z - u.z * v.y,
			u.z * v.x - u.x * v.z,
			u.x * v.y - u.y * v.x
		)
	);
}
