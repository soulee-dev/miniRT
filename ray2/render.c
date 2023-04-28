/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:52:54 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 23:23:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_color(int x, int y, t_color color, t_env *env)
{
	double	r;
	double	g;
	double	b;
	int		converted_color;
	double	scale;

	r = color.x;
	g = color.y;
	b = color.z;
	scale = 1.0 / env->img.samples_per_pixel;
	r *= scale;
	g *= scale;
	b *= scale;
	r = (int)(256 * clamp(r, 0.0, 0.999));
	g = (int)(256 * clamp(g, 0.0, 0.999));
	b = (int)(256 * clamp(b, 0.0, 0.999));
	converted_color = 0;
	converted_color = r * 256 * 256 + g * 256 + b;
	mlx_pixel_put(env->mlx.mlx, env->mlx.win, x, y, converted_color);
}

t_color	ray_color(t_ray *r, t_hittable_list *world, int depth)
{
	float			t;
	t_vec3			unit_direction;
	t_hit_record	rec;
	t_ray			ray;
	t_point3		target;

	if (depth <= 0)
		return (create_vec3_t(0.0));
	if (hittable_list_hit(*world, r, 0, (double)INFINITY, &rec))
	{
		target = add_vec3(add_vec3(rec.p, rec.normal), random_in_unit_sphere());
		ray.origin = rec.p;
		ray.direction = sub_vec3(target, rec.p);
		return (mul_n_vec3(ray_color(&ray, world, depth - 1), 0.5));
	}
	unit_direction = unit_vector(r->direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return (add_vec3(mul_n_vec3(create_vec3_t(1.0), 1.0 - t),
			mul_n_vec3(create_vec3_xyz(0.5, 0.7, 1.0), t)));
}

void	render(t_env *env)
{
	int		i;
	int		j;
	int		k;
	t_color	pixel_color;
	double	u;
	double	v;
	t_ray	r;

	i = 0;
	while (i < env->img.width)
	{
		j = 0;
		while (j < env->img.height)
		{
			pixel_color = create_vec3_t(0.0);
			k = 0;
			while (k < env->img.samples_per_pixel)
			{
				u = ((double)i + random_double()) / (env->img.width);
				v = ((env->img.height - (double)j)
						+ random_double()) / (env->img.height);
				r = camera_get_ray(env, u, v);
				pixel_color = add_vec3(pixel_color,
						ray_color(&r, &env->world, env->img.max_depth));
				k++;
			}
			write_color(i, j, pixel_color, env);
			j++;
		}
		i++;
	}
}
