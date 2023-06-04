/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:01:08 by soulee            #+#    #+#             */
/*   Updated: 2023/05/26 19:24:25 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_camera	camera(t_canvas *canvas, t_point3 lookfrom, \
	t_point3 lookat, double vfov);
t_canvas	canvas(int width, int height);
t_object	*object(int type, void *element, t_color albedo);
t_sphere	*sphere(t_point3 center, double radius);
t_cylinder	*cylinder(t_point3 center, t_vec3 dir,
				double diameter, double height);
t_plane		*plane(t_point3 point, t_vec3 normal);
t_light		*light_point(t_point3 orig,
				double bright_ratio, t_color light_color);
#endif