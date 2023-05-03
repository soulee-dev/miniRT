/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:52:04 by soulee            #+#    #+#             */
/*   Updated: 2023/05/03 19:49:59 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color	solid_color_value(t_solid_color solid_color)
{
	return (create_vec3_xyz(solid_color.red, \
		solid_color.green, solid_color.blue));
}
