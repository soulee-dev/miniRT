/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:52:54 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 16:08:25 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_color(int x, int y, t_color color, t_env *env)
{
	int	r;
	int	g;
	int	b;
	int	converted_color;

	converted_color = 0;
	r = color.x * 255.999;
	g = color.y * 255.999;
	b = color.z * 255.999;
	converted_color = r * 256 * 256 + g * 256 + b;
	mlx_pixel_put(env->mlx.mlx, env->mlx.win, x, y, converted_color);
}

int	hit_sphere(t_point3 center, double radius, t_ray r)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = sub_vec3(r.origin, center);
	a = dot(r.direction, r.direction);
	b = 2.0 * dot(oc, r.direction);
	c = dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

t_color	ray_color(t_ray r)
{
	double	t;
	t_vec3	unit_direction;
	t_color	color1;
	t_color	color2;

	if (hit_sphere)
	color1.x = 1.0;
	color1.y = 1.0;
	color1.z = 1.0;
	color2.x = 0.5;
	color2.y = 0.7;
	color2.z = 1.0;
	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (add_vec3(mul_n_vec3(color1, (1.0 - t)), mul_n_vec3(color2, t)));
}

void	render(t_env *env)
{
	int		i;
	int		j;
	t_color	pixel_color;
	t_ray	r;
	double	u;
	double	v;

	i = 0;
	while (i < env->img.width)
	{
		j = 0;
		while (j < env->img.height)
		{
			u = (double)i / (env->img.width);
			v = (env->img.height - (double)j) / (env->img.height);
			r.origin = env->cam.origin;
			r.direction = add_vec3(env->cam.lower_left_corner,
					add_vec3(mul_n_vec3(env->cam.horizontal, u),
						mul_n_vec3(sub_vec3(env->cam.vertical,
								env->cam.origin), v)));
			pixel_color = ray_color(r);
			write_color(i, j, pixel_color, env);
			j++;
		}
		i++;
	}
}
