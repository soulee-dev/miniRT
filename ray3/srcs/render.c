/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:01:26 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 18:17:42 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"

void	write_color(t_scene *scene, int x, int y, t_color color)
{
	double	r;
	double	g;
	double	b;
	int		converted_color;

	r = (int)(255.999 * color.x);
	g = (int)(255.999 * color.y);
	b = (int)(255.999 * color.z);
	converted_color = r * 256 * 256 + g * 256 + b;
	mlx_pixel_put(scene->mlx, scene->mlx_win, x, y, converted_color);
}

void	render(t_scene *scene)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color		pixel_color;

	i = 0;
	while (i < scene->canvas.width)
	{
		j = 0;
		while (j < scene->canvas.height)
		{
			u = (double)i / scene->canvas.width;
			v = (double)(scene->canvas.height - j) / scene->canvas.height;
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			write_color(scene, i, j, pixel_color);
			j++;
		}
		i++;
	}
}
