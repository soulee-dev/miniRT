/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:52:54 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 18:19:13 by soulee           ###   ########.fr       */
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

double	hit_sphere(t_point3 center, double radius, t_ray r)
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
	if (discriminant < 0.0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_color	ray_color(t_ray r)
{
	float		t;
	t_vec3		unit_direction;
	t_vec3		n;

	t = hit_sphere(create_vec3_xyz(0, 0, -1), 0.5, r);
	if (t > 0.0)
	{
		n = unit_vector(sub_vec3(at(r.origin, r.direction, t),
					create_vec3_xyz(0, 0, -1)));
		return (mul_n_vec3(create_vec3_xyz(n.x + 1.0,
					n.y + 1.0, n.z + 1.0), 0.5));
	}
	unit_direction = unit_vector(r.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return (add_vec3(mul_n_vec3(create_vec3_t(1.0), 1.0 - t),
			mul_n_vec3(create_vec3_xyz(0.5, 0.7, 1.0), t)));
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
