/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:52:22 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 13:47:44 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray	ray(t_point3 orig, t_vec3 dir);
t_vec3	at(t_ray r, double t);
t_ray	ray_primary(t_camera *cam, double u, double v);
t_color	ray_color(t_ray *r);

#endif