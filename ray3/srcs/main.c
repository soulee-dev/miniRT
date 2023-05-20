/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 15:13:22 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "render.h"

int	main(void)
{
	t_canvas	canv;
	t_camera	cam;
	void		*mlx;
	void		*mlx_win;
	t_object	*world;

	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));
	world = object(SHAPE_SPHERE, sphere(point3(-2, 0, -5), 2));
	add_obj(&world, object(SHAPE_SPHERE, sphere(point3(2, 0, -5), 2)));
	add_obj(&world, object(SHAPE_SPHERE, sphere(point3(0, -1000, 0), 990)));

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, canv.width, canv.height, "Ray3");
	render(&canv, &cam, mlx, mlx_win, world);
	mlx_loop(mlx);
	return (0);
}
