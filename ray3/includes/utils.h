/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:47:17 by soulee            #+#    #+#             */
/*   Updated: 2023/05/28 17:41:19 by soulee           ###   ########.fr       */
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
t_vec3		vec3(double x, double y, double z);
t_color		color(double r, double g, double b);
t_point3	point3(double x, double y, double z);
void		print_vec3(t_vec3 vec);

// vec2.c
t_vec3		add_vec3(t_vec3 u, t_vec3 v);
t_vec3		sub_vec3(t_vec3 u, t_vec3 v);
t_vec3		mul_vec3(t_vec3 u, t_vec3 v);
t_vec3		mul_n_vec3(t_vec3 u, double t);
t_vec3		div_n_vec3(t_vec3 u, double t);

// vec3.c
t_vec3		unit_vector(t_vec3 u);
double		dot(t_vec3 u, t_vec3 v);
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_vec3		cross(t_vec3 u, t_vec3 v);
t_vec3		min_vec3(t_vec3 u, t_vec3 v);

// object.c
void		add_obj(t_object **lst, t_object *new);
void		*last_obj(t_object *lst);

// string.c
size_t		count_strings(char **strs);
void		free_strs(char ***strs);
char		*make_code(const char *set);
char		**ft_split2(char const *s, const char *set);
double		ft_atof(const char *str);

// error.c
void		check_valid(double val, double min, double max);
void		check_valid_vec3(t_vec3 vec3, double min, double max);
void		check_error(int argc, char *argv[]);
void		exit_error(char *s);

// parser/arser.c
void		parse_line(t_scene *scene, char *line);
void		read_file(t_scene *scene, char *file_name);

// parser/parser1.c
void		add_ambient_light(t_scene *scene, char **strs);
void		add_camera(t_scene *scene, char **strs);
void		add_light(t_scene *scene, char **strs);

// parser/parser2.c
void		add_sphere(t_scene *scene, char **strs);
void		add_plane(t_scene *scene, char **strs);
void		add_cylinder(t_scene *scene, char **strs);

// init.c
t_scene		*scene_init(void);
int			quit(void);
int			key_down(int key, t_scene *scene);
void		key_hook(t_scene *scene);
void		print_count(t_scene *scene);

// cylinder_util.c
void		set_parameters(t_object *obj, t_discriminant *disc, t_ray *ray);
#endif