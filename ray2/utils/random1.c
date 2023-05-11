/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:40:38 by soulee            #+#    #+#             */
/*   Updated: 2023/05/11 16:35:16 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	random_double(void)
{
	static unsigned int	rseed = 0;

	rseed = (rseed * 1103515245 + 12345) & RAND_MAX;
	return (rseed / (RAND_MAX + 1.0));
}

double	random_double2(double min, double max)
{
	return (min + (max - min) * random_double());
}

t_vec3	random_vec3(void)
{
	return (create_vec3_xyz(random_double(), random_double(), random_double()));
}

t_vec3	random_vec3_2(double min, double max)
{
	return (create_vec3_xyz(random_double2(min, max),
			random_double2(min, max), random_double2(min, max)));
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	p;

	while (1)
	{
		p = random_vec3_2(-1, 1);
		if (length_squared(p) >= 1)
			continue ;
		return (p);
	}
}
