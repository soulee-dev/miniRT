/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:47:17 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 13:46:22 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// utils/random1.c
double		random_double(void);
double		random_double2(double min, double max);
t_vec3		random_vec3(void);
t_vec3		random_vec3_2(double min, double max);
t_vec3		random_in_unit_sphere(void);

// utils/random2.c
t_vec3		random_unit_vector(void);
t_vec3		random_in_hemisphere(t_vec3 normal);
int			random_int(int min, int max);

// utils/math1.c
double		length_squared(t_vec3 u);
double		length(t_vec3 u);
double		clamp(double x, double min, double max);
double		degrees_to_radians(double degrees);

// utils/vec1.c
t_vec3		add_vec3(t_vec3 u, t_vec3 v);
t_vec3		mul_n_vec3(t_vec3 u, double t);
t_vec3		mul_vec3(t_vec3 u, t_vec3 v);
double		dot(t_vec3 u, t_vec3 v);
t_vec3		sub_vec3(t_vec3 u, t_vec3 v);

// utils/vec2.c
t_vec3		div_n_vec3(t_vec3 u, double t);
t_vec3		unit_vector(t_vec3 u);
t_vec3		at(t_ray r, double t);
t_vec3		vec3(double x, double y, double z);
t_color		color(double x, double y, double z);
t_point3	point3(double x, double y, double z);

// utils/vec3.c
void		print_vec3(t_vec3 vec3);
int			near_zero(t_vec3 u);
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_vec3		refract(t_vec3 uv, t_vec3 n, double etai_over_etat);
t_vec3		cross(t_vec3 u, t_vec3 v);

// utils/vec4.c
t_vec3		random_in_unit_disk(void);
double		nth_vec3(t_vec3 u, int n);
t_vec3		min_vec3(t_vec3 u, t_vec3 v);
#endif