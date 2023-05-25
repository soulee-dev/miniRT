/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:47:17 by soulee            #+#    #+#             */
/*   Updated: 2023/05/25 21:48:04 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// math.c
double		length_squared(t_vec3 u);
double		length(t_vec3 u);
double		degrees_to_radians(double degrees);

// vec1.c
t_vec3		add_vec3(t_vec3 u, t_vec3 v);
t_vec3		mul_n_vec3(t_vec3 u, double t);
t_vec3		mul_vec3(t_vec3 u, t_vec3 v);
double		dot(t_vec3 u, t_vec3 v);
t_vec3		sub_vec3(t_vec3 u, t_vec3 v);

// vec2.c
t_vec3		div_n_vec3(t_vec3 u, double t);
t_vec3		unit_vector(t_vec3 u);
t_vec3		vec3(double x, double y, double z);
t_color		color(double x, double y, double z);
t_point3	point3(double x, double y, double z);

// vec3.c
void		print_vec3(t_vec3 vec3);
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_vec3		cross(t_vec3 u, t_vec3 v);

// vec4.c
t_vec3		min_vec3(t_vec3 u, t_vec3 v);

// object1.c
void		add_obj(t_object **lst, t_object *new);
void		*last_obj(t_object *lst);

// string.c
size_t		count_strings(char **strs);
void		free_strs(char ***strs);
char		*make_code(const char *set);
char		**ft_split2(char const *s, const char *set);

// error.c
void		check_valid(double val, double min, double max);
void		check_valid_vec3(t_vec3 vec3, double min, double max);
void		check_error(int argc, char *argv[]);
void		exit_error(char *s);

// parser.c
void		parse_line(t_scene *scene, char *line);
void		read_file(t_scene *scene, char *file_name);
#endif