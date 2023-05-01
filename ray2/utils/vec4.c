/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:54:56 by soulee            #+#    #+#             */
/*   Updated: 2023/04/30 00:56:17 by soulee           ###   ########.fr       */
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
