/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:01:26 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 15:02:27 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"

void	write_color(int x, int y, t_color color, void *mlx, void *mlx_win)
{
	double	r;
	double	g;
	double	b;
	int		converted_color;

	r = (int)(255.999 * color.x);
	g = (int)(255.999 * color.y);
	b = (int)(255.999 * color.z);
	converted_color = r * 256 * 256 + g * 256 + b;
	mlx_pixel_put(mlx, mlx_win, x, y, converted_color);
}

void	render(t_canvas *canv, t_camera *cam, void *mlx, void *mlx_win, t_object *world)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color		pixel_color;
	t_ray		ray;

	i = 0;
	while (i < canv->width)
	{
		j = 0;
		while (j < canv->height)
		{
			u = (double)i / canv->width;
			v = (double)(canv->height - j) / canv->height;
			ray = ray_primary(cam, u, v);
			pixel_color = ray_color(&ray, world);
			write_color(i, j, pixel_color, mlx, mlx_win);
			j++;
		}
		i++;
	}
}
