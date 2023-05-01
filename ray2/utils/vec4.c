/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:54:56 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 12:45:29 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	random_in_unit_disk(void)
{
	t_vec3	p;

	while (1)
	{
		p = create_vec3_xyz(random_double2(-1, 1), random_double2(-1, 1), 0);
		if (length_squared(p) >= 1)
			continue ;
		return (p);
	}
}

double	nth_vec3(t_vec3 u, int n)
{
	if (n == 0)
		return (u.x);
	else if (n == 1)
		return (u.y);
	else if (n == 2)
		return (u.z);
	return (0);
}
