/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:52:54 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 22:13:24 by soulee           ###   ########.fr       */
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

t_color	ray_color(t_ray *r, t_hittable_list *world)
{
	float			t;
	t_vec3			unit_direction;
	t_vec3			n;
	t_hit_record	rec;

	if (hittable_list_hit(*world, r, 0, (double)INFINITY, &rec))
		return (mul_n_vec3(add_vec3(rec.normal, create_vec3_t(1.0)), 0.5));
	unit_direction = unit_vector(r->direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return (add_vec3(mul_n_vec3(create_vec3_t(1.0), 1.0 - t),
			mul_n_vec3(create_vec3_xyz(0.5, 0.7, 1.0), t)));
}

void	render(t_env *env)
{
	int		i;
	int		j;
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
			u = (double)i / (env->img.width);
			v = (env->img.height - (double)j) / (env->img.height);
			r = camera_get_ray(env, u, v);
			pixel_color = ray_color(&r, &env->world);
			write_color(i, j, pixel_color, env);
			j++;
		}
		i++;
	}
}
