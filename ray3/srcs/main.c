/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/23 17:50:19 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "render.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	// Exit when malloc failed
	if (!scene)
		;
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	world = object(SPHERE, sphere(point3(-2, 0, -5), 2), color(0.5, 0, 0));
	add_obj(&world, object(SPHERE, sphere(point3(0, -1000, 0), 995), color(1, 1, 1)));
	add_obj(&world, object(SPHERE, sphere(point3(2, 0, -5), 2), color(0, 0.5, 0)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color(1, 1, 1), 0.5), color(0, 0, 0));
	scene->lights = lights;
	ka = 0.1;
	scene->ambient = mul_n_vec3(color(1, 1, 1), ka);
	return (scene);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_scene		*scene;

	scene = scene_init();

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, scene->canvas.width,  scene->canvas.height, "Ray3");
	render(scene, mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}
