/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:46:45 by soulee            #+#    #+#             */
/*   Updated: 2023/04/29 00:30:04 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_vec3(t_vec3 vec3)
{
	printf("x:%lf y:%lf z:%lf\n", vec3.x, vec3.y, vec3.z);
}

int	near_zero(t_vec3 u)
{
	double	s;

	s = 1e-8;
	return ((fabs(u.x) < s) && (fabs(u.y) < s) && (fabs(u.z) < s));
}
