/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:01:08 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 16:47:34 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_camera	camera(t_canvas *canvas, t_point3 orig);
t_canvas	canvas(int width, int height);
t_object	*object(int type, void *element, t_color albedo);
t_sphere	*sphere(t_point3 center, double radius);
t_light		*light_point(t_point3 orig, t_color light_color, double bright_ratio);
#endif