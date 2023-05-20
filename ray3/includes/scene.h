/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:01:08 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 14:55:30 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_camera	camera(t_canvas *canvas, t_point3 orig);
t_canvas	canvas(int width, int height);
t_object	*object(int type, void *element);
t_sphere	*sphere(t_point3 center, double radius);

#endif