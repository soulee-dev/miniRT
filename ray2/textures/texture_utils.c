/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:24:29 by soulee            #+#    #+#             */
/*   Updated: 2023/05/03 19:56:43 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color	value(t_texture texture, double u, double v, t_vec3 *p)
{
	t_color	ret_color;

	ret_color = create_vec3_t(0.0);
	if (texture.type == TEXTURE_SOLID_COLOR)
		ret_color = solid_color_value(texture.solid_color);
	else if (texture.type == TEXTURE_CHECKER)
		ret_color = checker_value(texture.checker, u, v, p);
	return (ret_color);
}
