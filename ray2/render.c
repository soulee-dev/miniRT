/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:52:54 by soulee            #+#    #+#             */
/*   Updated: 2023/05/18 15:20:40 by soulee           ###   ########.fr       */
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
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);
	r = (int)(256 * clamp(r, 0.01, 0.999));
	g = (int)(256 * clamp(g, 0.01, 0.999));
	b = (int)(256 * clamp(b, 0.01, 0.999));
	converted_color = r * 256 * 256 + g * 256 + b;
	mlx_pixel_put(env->mlx.mlx, env->mlx.win, x, y, converted_color);
}

t_color	ray_color(t_ray *r, t_env *env, \
	t_hittable_list *world, int depth)
{
	t_hit_record	rec;
	t_ray			scattered;
	t_color			attenuation;
	t_color			emitted;
	t_color			ambient_light = create_vec3_t(0.0);

	if (depth <= 0)
		return (ambient_light);
	if (!hittable_list_hit(world, r, EPSILON, INFINITY, &rec))
		return (ambient_light);
	emitted = material_emitted(rec.mat_ptr, rec.u, rec.v, &rec.p);
	if (!hit_material(r, &rec, &attenuation, &scattered))
		return (add_vec3(emitted, ambient_light));
	return (
		add_vec3(emitted, \
			mul_vec3(attenuation, \
				ray_color(&scattered, env, world, depth - 1)))
	);
}

void	render2(t_env *env, t_cam *cam, int i, int j)
{
	t_color	pixel_color;
	int		k;
	double	u;
	double	v;
	t_ray	r;

	pixel_color = create_vec3_t(0.0);
	k = 0;
	while (k < env->img.samples_per_pixel)
	{
		u = ((double)i + random_double()) / (env->img.width);
		v = ((env->img.height - (double)j)
				+ random_double()) / (env->img.height);
		r = camera_get_ray(cam, u, v);
		pixel_color = add_vec3(pixel_color, \
			ray_color(&r, env, \
				&env->world, env->img.max_depth));
		k++;
	}
	write_color(i, j, pixel_color, env);
}

void	render(t_env *env, t_cam *cam)
{
	int		i;
	int		j;
	t_progress progress = create_progress(env->img.width, 30);

	printf("Render Start\n");
	i = 0;
	while (i < env->img.width)
	{
		j = 0;
		update_progress(&progress, i);
		while (j < env->img.height)
		{
			render2(env, cam, i, j);
			j++;
		}
		i++;
	}
	printf("Done!\n");
}
