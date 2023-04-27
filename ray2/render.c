/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:52:54 by soulee            #+#    #+#             */
/*   Updated: 2023/04/27 17:57:19 by soulee           ###   ########.fr       */
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

	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (add_vec3())
}

void	render(t_env *env)
{
	int		i;
	int		j;
	t_color	pixel_color;

	i = 0;
	while (i < env->img.height)
	{
		j = 0;
		while (j < env->img.width)
		{
			pixel_color.x = (double)j / (env->img.width - 1);
			pixel_color.y = (double)i / (env->img.height - 1);
			pixel_color.z = 0.25;
			write_color(j, i, pixel_color, env);
			j++;
		}
		i++;
	}
}
