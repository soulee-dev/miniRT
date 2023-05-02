/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:48:52 by soulee            #+#    #+#             */
/*   Updated: 2023/05/02 18:51:48 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	hit(t_shape shape, t_ray *r, double t_min, \
	double t_max, t_hit_record *rec)
{
	int	is_hit;

	is_hit = 0;
	if (shape.type == SHAPE_SPHERE)
		is_hit = sphere_hit(shape.sphere, r, t_min, t_max, rec);
	
}