/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/25 21:45:08 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		exit_error("error: malloc failed (scene)");
	scene->canvas = canvas(400, 300);
	scene->mlx = mlx_init();
	scene->mlx_win = mlx_new_window(scene->mlx, scene->canvas.width, \
		scene->canvas.height, TITLE);
	scene->camera = camera(&scene->canvas, point3(26, 10, 6), point3(0, 5, 0), 30);
	world = object(SP, sphere(point3(0, 0, 0), 2), color(0.5, 0, 0));
	add_obj(&world, object(SP, sphere(point3(0, -1000, 0), 995), color(1, 1, 1)));
	add_obj(&world, object(CY, cylinder(point3(2, -1, -5), vec3(0, 1, 0), 1, 5), color(0, 0.5, 0)));
	add_obj(&world, object(PL, plane(point3(0, 0, 0), vec3(0, 1, 0)), color(0, 0, 1)));
	scene->world = world;
	// change parameter order of light_point.
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color(1, 1, 1), 0.5), color(0, 0, 0));
	scene->lights = lights;
	ka = 0.1;
	scene->ambient = mul_n_vec3(color(1, 1, 1), ka);
	return (scene);
}

int	quit(void)
{
	exit(0);
}

int	key_down(int key, t_scene *scene)
{
	(void) scene;
	if (key == KEY_ESC || key == KEY_Q)
		quit();
	return (0);
}

void	key_hook(t_scene *scene)
{
	mlx_hook(scene->mlx_win, DESTROY, 0, quit, NULL);
	mlx_hook(scene->mlx_win, KEYDOWN, 0, key_down, scene);
}

int	main(int argc, char *argv[])
{
	t_scene		*scene;

	check_error(argc, argv);
	scene = scene_init();
	read_file(scene, argv[1]);
	key_hook(scene);
	render(scene);
	mlx_loop(scene->mlx);
	return (0);
}

// Normalize input direction vectors when input.
// Elements which are defined by a capital letter can only be declared once in the scene.