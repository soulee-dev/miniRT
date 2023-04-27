/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:45:27 by soulee            #+#    #+#             */
/*   Updated: 2023/04/27 17:48:45 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	length_squared(t_vec3 u)
{
	return (u.x * u.x + u.y * u.y + u.z * u.z);
}

double	length(t_vec3 u)
{
	return (sqrt(length_squared(u)));
}
