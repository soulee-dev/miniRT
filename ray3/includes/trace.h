/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:52:22 by soulee            #+#    #+#             */
/*   Updated: 2023/05/23 19:26:55 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray	ray(t_point3 orig, t_vec3 dir);
t_vec3	at(t_ray *r, double t);
t_ray	ray_primary(t_camera *cam, double u, double v);
t_color	ray_color(t_scene *scene);

t_color	phong_lighting(t_scene *scene);
t_color	point_light_get(t_scene *scene, t_light *light);
int		in_shadow(t_object *objs, t_ray light_ray, double light_len);

// hit
int		hit(t_object *objs, t_ray *ray, t_hit_record *rec);
int		hit_obj(t_object *objs, t_ray *ray, t_hit_record *rec);
int		hit_sphere(t_object *obj, t_ray *ray, t_hit_record *rec);
int		hit_cylinder(t_object *obj, t_ray *ray, t_hit_record *rec);
void	set_face_normal(t_ray *r, t_hit_record *rec);
#endif