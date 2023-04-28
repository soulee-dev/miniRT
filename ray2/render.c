/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:52:54 by soulee            #+#    #+#             */
/*   Updated: 2023/04/28 10:20:41 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_color(int i, int j, t_color color, t_env *env)
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
	mlx_pixel_put(env->mlx.mlx, env->mlx.win, i, j, converted_color);
}

t_color	ray_color(t_ray r)
{
	double	t;
	t_vec3	unit_direction;
	t_color	color1;
	t_color	color2;

	color1.x = 1.0;
	color1.y = 1.0;
	color1.z = 1.0;
	color2.x = 1.0;
	color2.y = 1.0;
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

	i = 0;
	while (i < env->img.height)
	{
		j = 0;
		while (j < env->img.width)
		{
			r.origin = env->cam.origin;
			r.dir = 
			pixel_color = ray_color();
			write_color(j, i, pixel_color, env);
			j++;
		}
		i++;
	}
}
